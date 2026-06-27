# Decision research: Async runtime, parallelism & idle scheduling

**Status:** Researching <!-- Researching / Recommending / Decided / Deferred -->
**Owner:** Rovin  ·  **Date:** 2026-06-27

## Question
What **async runtime + parallelism** model should pandex use, and how should it schedule heavy enrichment to **yield to interactive use** and prefer **device-idle troughs**?

## Context & constraints
- **Async** enrichment of scanned files (embeddings/keywords) that must **yield to interactive use** and prefer **idle troughs**.
- **Bounded, backpressured** queues; surgical work; cross-platform incl. low-end (don't oversubscribe CPU).
- Permissive deps only.
- Downstream deps largely assume tokio (see [`storage-connectors.md`](storage-connectors.md), [`fs-scan-and-watch.md`](fs-scan-and-watch.md)).

## Options

### Async runtime
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **tokio** (+ `tokio-util`) | Async I/O runtime | De-facto standard; opendal/object_store/notify v9 all target it; `Semaphore`, bounded `mpsc`, `spawn_blocking`, `yield_now`, `interval`; MIT | Larger binary; must not block workers; no true priority scheduling (build it with semaphores/yields) |
| ~~async-std~~ | Async runtime | — | **Officially deprecated** (→ smol); avoid |
| smol | Minimal async runtime | Tiny, composable; MIT/Apache | Small ecosystem; needs bridging for tokio-targeted deps |

### CPU parallelism
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **rayon** | Data-parallel CPU | `par_iter`; work-stealing; pairs with blake3's `rayon` feature; MIT/Apache | Synchronous — bridge via `spawn_blocking`; don't oversubscribe against tokio |

### Idle / usage-trough detection
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **sysinfo** | CPU / memory metrics | Primary "is the device idle" signal; cross-platform; MIT | Frequent API churn; poll-based (not event-driven); no user-input idle |
| **starship-battery** | AC / battery state | Best-maintained battery crate; ISC; Win/macOS/Linux/FreeBSD | Low independent community; pre-1.0 |
| user-idle | User input idle time | Answers "is the user AFK?"; cross-platform (Win/macOS); MIT/Apache | On Linux **X11-only** (no Wayland idle); small/dormant |
| ~~battery~~ | AC/battery state | — | Abandoned since 2020 → skip |

## Recommendation
Use **tokio** as the runtime (effectively forced by the connector/watcher dependency chain) with **rayon** for CPU-bound parallelism, bridged via `spawn_blocking`; never the deprecated `async-std`. Model enrichment as a **bounded, backpressured pipeline**: a `tokio::sync::mpsc` bounded channel for ingest plus a `tokio::sync::Semaphore` to cap concurrent enrichments, with `yield_now()` in long tasks so interactive work isn't starved. Gate heavy work behind an **idle/trough check** combining **sysinfo** (CPU/memory) + **starship-battery** (prefer on-AC) + optionally **user-idle** (AFK; accept the Wayland gap), re-evaluated on a `tokio::time::interval` to raise/lower the semaphore's permit count. On low-end devices, **cap rayon threads** (e.g. `available_parallelism / 2`) to avoid oversubscribing alongside tokio. Proposal, not a lock.

## Open questions
- Default concurrency / permit policy — static vs **dynamic from load**; per-device tuning.
- Idle-signal weighting: CPU-only vs CPU + AC + AFK; what thresholds?
- Should idle/trough **scheduling become its own note** (`scheduling.md`) once it outgrows these crates?
- rayon vs tokio thread-pool **sizing** on low-end devices to avoid CPU oversubscription.
- `notify` v9 tokio feature timing (cross-ref [`fs-scan-and-watch.md`](fs-scan-and-watch.md)).

## References
- https://github.com/tokio-rs/tokio · https://crates.io/crates/tokio-util · https://github.com/smol-rs/smol
- https://github.com/rayon-rs/rayon
- https://github.com/GuillaumeGomez/sysinfo · https://github.com/starship/rust-battery (starship-battery) · https://github.com/olback/user-idle-rs
