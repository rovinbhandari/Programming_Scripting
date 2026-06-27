# Decision research: Storage connectors (Sources)

**Status:** Researching <!-- Researching / Recommending / Decided / Deferred -->
**Owner:** Rovin  ·  **Date:** 2026-06-27

## Question
How should pandex talk to many storage backends — local plus S3/GCS/Azure and personal clouds (Dropbox, Google Drive, OneDrive) — behind **one pluggable `Source` interface**?

## Context & constraints
- **Pluggable Source connectors:** a uniform API across local + many clouds.
- Async; cross-platform; minimal; permissive deps.
- Local scanning specifics (traversal/watch/hash) live in [`fs-scan-and-watch.md`](fs-scan-and-watch.md); this note is about the **connector abstraction**.

## Options
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **opendal** | Unified API, 70+ backends | Covers local + S3/GCS/Azure **and** Dropbox/Google Drive/OneDrive under one `Operator`; layers for retry/timeout/concurrency-limit/caching; optional blocking API; **Apache TLP**; Apache-2.0 | Pre-1.0 (breaking 0.x minors); large dep surface; some cloud backends less battle-tested |
| **object_store** | S3/GCS/Azure + local | Very high quality; stable API; Arrow/DataFusion ecosystem; MIT/Apache | **No Dropbox/OneDrive/Google Drive**; tokio required; `aws-lc-rs` crypto dep |
| ~~rclone~~ | Go CLI, 70+ providers | Most mature multi-cloud; handles OAuth/token refresh; MIT | **Not a library** — subprocess only; IPC + auth-state awkward; heavyweight runtime dep |

## Recommendation
Adopt **opendal** as the connector layer — it's the only Rust-native option that already spans local plus the **consumer clouds** pandex cares about (Dropbox, Google Drive, OneDrive) under a single `Operator` API, and its **layers** system supplies retry/timeout/concurrency-limit middleware for free. Wrap it behind pandex's own `Source` trait so a backend can be swapped, or an `rclone` subprocess bolted on as an escape hatch for any provider opendal lacks. **object_store** is the higher-quality pick if pandex ever narrows to just S3/GCS/Azure. Pin opendal carefully given its pre-1.0 status. Note the boundary with [`fs-scan-and-watch.md`](fs-scan-and-watch.md): the **local** `Source` may use pandex's specialized scanner/watcher (`ignore`/`notify`/`blake3`) internally rather than opendal's `fs` backend — opendal is primarily the uniform connector layer for **cloud** and remote stores. Proposal, not a lock.

## Open questions
- Accept opendal's pre-1.0 churn now, or start **local-only** (`std::fs` + [`fs-scan-and-watch.md`](fs-scan-and-watch.md)) and add opendal when cloud lands?
- Which connectors are **in scope for v1** (likely local first; clouds later)?
- OAuth **token storage & refresh** strategy for personal-cloud connectors (Drive/Dropbox/OneDrive)?
- Do we need the `rclone` subprocess escape hatch for long-tail providers?

## References
- https://github.com/apache/opendal · https://crates.io/crates/opendal
- https://github.com/apache/arrow-rs-object-store · https://crates.io/crates/object_store
- https://github.com/rclone/rclone
