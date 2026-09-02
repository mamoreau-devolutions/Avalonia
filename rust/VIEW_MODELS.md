# Rust view models with managed AXAML

`rust_vm_axaml` validates the application architecture suggested by Avalonia
maintainers:

- Rust owns application state, collection mutations, commands, and background
  work.
- Managed AXAML owns the presentation tree, Fluent templates, compiled
  bindings, and accessibility.
- A generated COM-shaped model/sink contract carries state transitions without
  exposing controls to the Rust model.

The generated `SampleViewModelAdapter` implements presentation-facing property
notification and commands. It forwards edits and commands over the stable,
ID-based `IAvnRustViewModel` transport implemented by Rust. Rust publishes
resulting state through `IAvnRustVmSink`; sink calls from Rust workers are
dispatched to Avalonia's UI thread.

## Generated application contract

`view-model.ir.json` is the source of truth for model, property, collection,
command, and view IDs. The generator produces:

- typed Rust model traits, sinks, dispatch, and `AppScope::mount_*` methods
- managed compiled-binding adapters in the presentation project
- an AOT-rooted host view registry
- [a readable contract report](view-model.contract.md)

The handwritten Rust and managed interop layers know only the generic
transport. Adding an application model or view does not add methods to that
transport or require handwritten host dispatch.

The current transport supports string, integer, Boolean, double, and
enum-backed scalar properties (nullable for strings and nested view models),
plus observable collections of strings or nested view models. Command
parameters reference writable string properties. IDs are explicit positive
integers and remain stable when schema entries are reordered.

## Project boundaries

`Avalonia.Rust.Interop` contains only the neutral generated-COM interfaces.
`RustViewModelSample.Managed` owns AXAML, its generated adapter, and view
code-behind. `Avalonia.Host` references presentation assemblies and consumes
only the generated registry. A product host can replace the sample
presentation project with its own generated view assemblies.

The adapter detaches the Rust sink when its window closes. Updates already in
flight are dispatched to the UI thread only while the adapter remains alive;
late updates after detach are ignored. `AppScope` keeps the Rust model and
mounted top-level alive until deterministic application-scope cleanup.

The NativeAOT sample proves:

- initial Rust state flowing into compiled AXAML
- a two-way text edit flowing into Rust and back
- a synchronous Rust command updating a bound count
- a Rust-owned collection mutation updating a bound ListBox
- Rust background work publishing asynchronous status
- deterministic model/sink detachment when the window closes

This is the recommended full-application direction. The generated code-first
builder remains useful for small tools, tests, and applications that do not
want AXAML. Future projection growth should be justified by one of these two
application modes rather than raw API-coverage goals.

## Rust value converters

Rust can also author `IValueConverter` implementations consumed by both
compiled and dynamic AXAML, through the same generated pipeline.

### Transport

`IAvnRustValueConverterProvider` (in `Avalonia.Rust.Interop`) is a separate
COM-like object from `IAvnRustViewModel`: its ownership is disjoint from the
`Arc<Mutex<Model>>` that backs a mounted view model, and its single `Convert`
method is invoked without any provider-level lock. Converters must be pure —
they must not read or lock `ViewModel` state — because the same provider can
be invoked concurrently from any thread that evaluates a binding.

Values, converter parameters, and results are versioned tagged scalars, not
arbitrary managed objects: `null`, string, 64-bit integer, Boolean, double,
`AvaloniaProperty.UnsetValue`, and `BindingOperations.DoNothing`. The ABI also
carries the conversion direction (Convert/ConvertBack), a target-kind hint,
and the binding culture, for forward compatibility, even though the generated
scalar converters in this stage do not use the target kind or culture yet.
Arbitrary managed values are rejected by the managed adapter
(`Avalonia.Rust.RustValueConverter`) before crossing the ABI, with a
`BindingNotification` error rather than a thrown exception. Result and error
strings are allocated by Rust through the host's `avn_alloc_utf16` export —
the same allocator backing `avn_free` — so the managed caller can free them
with `Marshal.FreeCoTaskMem` without a cross-allocator mismatch. This is not
JSON, and there is no arbitrary managed object support: this is a deliberate,
documented scope limit for this stage.

### Registration and lifetime

Exactly one provider is registered for the lifetime of the running
application (`Avalonia.Rust.RustValueConverterRuntime`, a lock-free,
process-wide registry read on every conversion). `AppScope`'s
`register_value_converters` (generated per schema) registers it once; a
second, different provider is rejected rather than silently replacing the
first, so an already-realized DataTemplate cannot have its converters swapped
out from under it. Because the registry is a static, process-wide lookup
rather than something resolved once at window-construction time, converters
resolve correctly for DataTemplate/ControlTemplate content realized well
after the window that declared them was constructed (for example inside a
`ListBox` item template or a `ContentControl.ContentTemplate` built lazily by
a `ContentPresenter`). Applications and views that never use Rust value
converters are unaffected: the provider is nullable, and `SetValueConverterProvider(null)`
is always valid. `AppScope` releases the registration during its own cleanup,
so the provider does not outlive application shutdown. Registration uses the
separately versioned `IAvnApplication2` interface, so a newer Rust client fails
safely when an older host lacks converter support.

### Generated surface

The view-model IR's schema-wide `converters` array declares each converter's
ID, name, value/parameter/result kinds, and convert-back capability. The
generator produces:

- a Rust `ValueConverters` trait with one named method per converter (plus a
  `_back` method when convert-back is declared), typed by the declared
  scalar kinds — application authors never see raw converter IDs
- an internal dispatch bridge mapping IDs to those named methods
- a managed static class per converter (for example `CountToLabelConverter`)
  exposing a ready `IValueConverter` instance
- for each view that declares `converters`, a `mount_<view>_with_converters`
  Rust API alongside the existing `mount_<view>` API, so views without
  converters keep their original, unchanged mount function

`rust_vm_axaml` and `rust_dynamic_vm_axaml` both register the same
`CountToLabel` converter (formatting `Count` as `"Rust count: {n}"`) and
consume the same generated managed `CountToLabelConverter.Instance` from
their AXAML, including from a `DataTemplate` resource realized lazily by a
`ContentPresenter`.

## Real-application data model support

The transport described above proved the architecture with scalar properties,
string collections, and commands. Real applications also need nested view
models, values that may be absent, richer scalar kinds, ordered collection
edits, command availability, and validation — all without widening the core
ABI's method count per feature or forking the canonical IR/generator pipeline
for C# and Rust.

### A second, independently versioned sink interface

Every capability below is carried by `IAvnRustVmSink2`, a second interface
(new IID, own vtable) that a generated adapter implements *in addition to*
`IAvnRustVmSink`, not a replacement for or extension of it. This keeps ABI
compatibility explicit: `IAvnRustVmSink` (property/collection-append) is
untouched, so nothing that worked before regresses, while
`ViewModelSink::new` resolves `IAvnRustVmSink2` once via `QueryInterface` when
a model attaches and fails the attach explicitly (`E_NOINTERFACE`) if an older,
not-yet-regenerated adapter is missing it — the same versioning pattern
already used for `IAvnApplication2` (Rust value converters). There is no
partial/degraded mode: a generated adapter and its Rust model are always
regenerated together from the same schema, so v2 is always present in
practice; the explicit failure exists for the case where that invariant is
violated (an adapter built from a stale schema).

`IAvnRustVmSink2` adds: `SetNull`, `SetModel`, `AddModel`, `InsertString`,
`InsertModel`, `ReplaceString`, `ReplaceModel`, `RemoveAt`, `MoveItem`,
`ClearCollection`, `SetCommandEnabled`, and `SetPropertyError` — generic,
ID-addressed operations exactly like the v1 transport, never named after an
application's models or members.

### Nullable values

A string property may declare `"nullable": true`. Rust publishes "no value"
through `IAvnRustVmSink2.SetNull(propertyId)` instead of an empty string;
managed backing fields become `string?` and the generated named Rust setter
becomes `Option<impl AsRef<str>>` (`None` calls `set_null`, `Some` calls the
existing `SetString`). Inbound writes are always concrete — an application
that needs the user to explicitly clear a nullable property to `None` does so
through a dedicated command (see `ClearNickname` in the sample), the same way
any other state transition reaches Rust. This keeps the *inbound* `IAvnRustViewModel`
transport completely unchanged; only the outbound direction gained a new
signal.

### Enums

`enums` is a new top-level, schema-wide array (`{ id, name, managedNamespace,
members: [{ name, value }] }`). Enum member values are explicit and stable,
exactly like property/command/model IDs. An enum-kind property is transported
as the existing `Integer` wire kind — there is no new ABI scalar kind — but
the generator emits a real C# `enum` and a real Rust `#[repr(i64)] enum` (with
`TryFrom<i64>`) so application code never sees a raw integer. Both the
outbound (`SetInteger` dispatch) and inbound (`Priority::try_from`) directions
explicitly reject an out-of-range value rather than silently truncating,
defaulting, or aliasing it to a defined member.

### Nested view models

A property (or a collection element) can declare `"kind": "Model"` with a
`modelName` (or `elementModelName`) referencing another entry in the schema's
`models` array. A nested model is *not* a new concept at the ABI level: Rust
wraps it in exactly the same `IAvnRustViewModel` capability a top-level mount
uses, just without making it a window, and publishes it through
`IAvnRustVmSink2.SetModel`/`AddModel`/`InsertModel`/`ReplaceModel`. The
managed side constructs an ordinary instance of that nested model's own
generated adapter — the exact same adapter type/constructor a top-level view
would use — so a nested model's own properties, commands, and validation
errors are all first-class and independently generated; nothing about nested
support is hand-written per model. A nested-model property is always
`nullable` (there may be no nested value yet) and never `writable` from
managed code — its own properties are writable independently, through its own
adapter.

Rust-side lifetime is explicit rather than relying on `ComWrappers` reference
counting alone: `ViewModelSink` keeps a small per-mount registry
(`NestedSlots`) of the nested COM handles it has published — one slot per
nested-model property (replacing drops the previous handle) and one ordered
list per nested-model collection (mirrored to stay in sync with insert/
remove/move/replace/clear). Dropping a slot immediately releases Rust's
contribution to that nested object's reference count; dropping the whole
sink (when a mount detaches) releases everything still tracked. This is what
keeps repeated attach/replace/detach cycles from accumulating live native
references — covered by Rust unit tests in `view_model.rs`
(`nested_property_slot_replaces_and_drops_the_previous_handle`,
`nested_collection_slots_track_insert_move_replace_remove_and_clear`,
`dropping_the_nested_slots_releases_every_tracked_handle`).

The sample's `SampleViewModel.Address` (`AddressViewModel`, toggled on/off by
`ToggleAddressCommand`) demonstrates a nested property; `SampleViewModel.Tasks`
(a collection of `TaskItemViewModel`) demonstrates a nested collection whose
items each carry their own two-way `Done` checkbox — proving nested item
notifications flow directly to and from that specific item's own sink, not
through the parent.

### Collection insert/remove/replace/move/clear

Beyond the original `AddString` (append), `IAvnRustVmSink2` adds ID-addressed,
index-based `Insert`/`Replace`/`RemoveAt`/`MoveItem`/`ClearCollection`
operations, generated per collection and per element kind (`insert_items`,
`replace_tasks`, `remove_tasks`, `move_tasks`, `clear_tasks`, and so on).
Managed dispatch maps these directly onto `ObservableCollection<T>.Insert`/
`Move`/`RemoveAt`/`Clear`, so a bound `ListBox` observes the same granular
`NotifyCollectionChangedAction` a real end-user edit would produce, not a
wholesale re-render. Removing, replacing, or clearing a `Model`-kind
collection disposes the nested adapter(s) it evicts.

### Command `CanExecute` state

Rust can publish a command's enabled/disabled state with
`IAvnRustVmSink2.SetCommandEnabled` (generated as, for example,
`set_save_enabled(bool)`). The generated `DelegateCommand` (both the compiled
adapter's and the dynamic reflectable adapter's) carries real `CanExecute`
state and raises `CanExecuteChanged` only when the state actually changes.
The sample disables `SaveCommand` for the duration of the Rust async worker
and re-enables it on completion.

### Validation-error projection

Rust can publish (or clear) a human-readable validation message for any
property with `IAvnRustVmSink2.SetPropertyError(propertyId, message)`
(generated as, for example, `set_name_error(Option<&str>)`). Generated
adapters implement `INotifyDataErrorInfo`, so Avalonia's binding pipeline
surfaces the error (and its `:error` pseudo-class / `DataValidationErrors`)
automatically on any two-way-bound control — no `ValidatesOnDataErrors` flag
or extra AXAML is required. Rust owns the validation *decision*; the managed
side only ever projects it. The sample rejects an empty `Name`.

### The dynamic (reflectable) path

`ReflectableRustViewModelAdapter` implements every capability above through
the same `RustViewModelDescriptor`/`RustViewModelPropertyDescriptor`/
`RustViewModelCollectionDescriptor` metadata already used for compiled-vs-
dynamic parity, so `rust_dynamic_vm_axaml` exercises the identical Rust model
as `rust_vm_axaml`. Two scope choices keep the reflection-based path
approachable: an enum-kind property boxes the *concrete* generated enum type
(inferred from the descriptor's boxed `InitialValue`, not a separate type
parameter), so `RustBindingExtension`-bound text still shows the member name;
and a nested view model's own properties are always bound at the top level of
its own `DataTemplate` (the `DataContext` becomes the nested adapter, exactly
like a `ListBox` item template) rather than through a dotted binding path, so
`RustBindingExtension`'s single-segment path resolution needs no change.

### Conformance coverage

`Avalonia.Host.Tests/RustVmAdapterTests.cs` exercises lifecycle (repeated
attach/detach, nested attach/dispose, dispose-then-dispose-again is a no-op),
thread affinity (worker-thread sink publication dispatched to a queued
"UI thread" and late updates after dispose ignored, for both the compiled and
dynamic adapters), invalid-contract behavior (unknown property/collection/
command IDs and out-of-range enum values return a negative HRESULT and leave
existing state untouched, on every new v2 method), and leak-shaped behavior
(disposing a parent adapter disposes every nested model/collection item
exactly once). `rust/avalonia/src/view_model.rs` covers the same
nested-handle lifetime guarantees at the Rust `NestedSlots` level, including a
200-iteration create/drop cycle with an instrumented `Drop` counter.

## Stage 27: immutable worker batches

`IAvnRustVmSink3` is a separately versioned capability; v1 and v2 vtables are
unchanged. It accepts an immutable `IAvnRustVmUpdateBatch`, which is retained
and inspected only by one `Dispatcher.UIThread.Post` callback. Submission never
uses `Invoke`, never waits, and never calls back into Rust on the submitting
stack. Keep v1/v2 calls only for UI-thread compatibility; worker and
high-volume publishers must use the generated `sink.batch(generation)` builder
and `sink.submit_batch(batch)`.

Generations strictly increase per model. The adapter applies a generation only
when it is greater than the last applied value; equal and lower generations
complete as `Stale`. `BatchCompletion` (or `submit_batch_with_callback`) reports
`Applied`, `Stale`, `Cancelled` after disposal, or `Error` after UI processing.
The batch owns strings and retained nested model COM references until that
outcome, and the FFI accessors validate pointers, indices, and tags under a
panic boundary. The batch object also exposes the separately versioned
`IAvnRustVmUpdateBatch2` ownership-commit capability described below; the
original batch IID and vtable are unchanged.

`replace_*_snapshot` stages a complete string or nested-model collection then
commits it with one collection `Reset`; it is the required path for large
snapshots (including 100K items). Batch validation reads every operation before
mutation so malformed operations cannot partially update managed state.

### The shared staged transactional engine

Both adapter kinds - the IR-generated adapters and
`ReflectableRustViewModelAdapter` - apply batches through one engine,
`Avalonia.Rust.RustVmBatchCoordinator`. Adapters do not implement transactional
logic; they implement `IRustVmBatchTarget`, which only describes their schema
and performs notification-free stores. A batch runs in four ordered phases:

1. **Decode.** Every operation is read and every getter HRESULT is checked. An
   unknown tag, a negative count, a null operation or a failing getter fails the
   batch before anything is inspected further.
2. **Plan and validate.** Every target id, exact property wire kind, nullable
   eligibility, enum domain, command id, collection element kind and ordered
   index is validated. Collection indices are checked against a working copy
   that replays the batch's own ordering, so `insert`, `replace`, `remove`,
   `move`, `clear` and snapshot operations are validated against the state they
   would really see. `ClearCollection` is a first-class operation for both
   element kinds. Nothing on the target is mutated in this phase.
3. **Stage.** Every nested adapter the plan installs is constructed and attached
   off to the side. A nested attach failure disposes every adapter staged so
   far and leaves target state and notifications completely untouched. Only
   models that survive the folded plan are attached at all, so a model replaced
   or removed later in the same batch is never attached.
4. **Commit, then publish.** Fields, command `CanExecute` state, validation
   errors and collection contents are stored with no externally observable
   notification (collections go through `IRustVmBatchCollection.SetContents`).
   The producer's nested ownership is then transferred through
   `IAvnRustVmUpdateBatch2.CommitOwnership`, and only after that are coalesced
   `PropertyChanged`, `ErrorsChanged`, `CanExecuteChanged` and at most one
   collection `Reset` per changed collection published; each is isolated, so a
   throwing observer cannot suppress the others. State is already fully
   committed at that point, so the batch still completes as `Applied`: a
   notification failure is logged, never reported as a rollback that did not
   happen.

Nested adapters a batch displaces are disposed after publication, so ownership
transfer is complete exactly once whether the batch replaced a model property,
replaced or removed a collection element, cleared a collection or replaced a
whole snapshot.

### Ownership transfer ordering

`IAvnRustVmUpdateBatch2` is a separately versioned IID and vtable exposed by the
same batch object; the original `IAvnRustVmUpdateBatch` contract is untouched.
The adapter requires it and resolves it before it decodes or stages anything, so
a producer that cannot hand over ownership at the right point fails the batch
with zero mutation.

`CommitOwnership` runs exactly once, strictly between the notification-free
state commit and the first notification. That ordering is what makes a reentrant
publish safe: when a notification observer synchronously publishes a further
nested update through the v1/v2 sink, the batch's own nested handles are already
reconciled on the producer side, so the observer's update applies on top of them
instead of racing them. A batch that is rejected during validation or staging,
or that completes as stale, cancelled or in error, never receives the call and
simply drops its candidate handles. Completion still arrives last, after every
notification.

### The non-reentrant batch lifecycle gate

`RustVmBatchGate` replaces the previous reentrant lock. A batch takes exclusive
ownership of the target for its whole commit and publication. If an observer
disposes the adapter from a notification, disposal is marked pending and the
detach plus nested cleanup run only after the batch leaves the gate, so the
batch never publishes into a half-detached adapter and staged adapters are never
installed after final disposal. Concurrent `Dispose` calls serialize on the same
cleanup and detach exactly once. Batches queued before disposal, and any
submitted afterwards, complete as `Cancelled`.

### Rust-side ownership

Each batch carries its managed-visible operations and a matching nested
ownership delta. The delta is applied to `NestedSlots` exactly once, by the
batch's `CommitOwnership` capability, which managed code calls between the state
commit and the notifications. A batch that never reaches that point - stale,
cancelled, rejected or failed - simply drops the callback, releasing its
candidate handles without touching the slots that are still live. Slot updates
are bounds-checked rather than panicking, and a model snapshot installs a real
slot list, so synchronous v1/v2 `remove`/`move`/`replace`/`clear` keeps working
after a batch snapshot has been applied.

`IAvnRustVmSink3` is resolved lazily on first submission and cached. Only
`E_NOINTERFACE` is cached as "absent": any other `QueryInterface` failure is
cached and reported verbatim, so a transport error is never silently downgraded
to "this host has no batch support". A host that only implements v1/v2 still
attaches and publishes normally, and only `submit_batch` reports
`E_NOINTERFACE`.

