# Decision research: Filesystem scan, watch & hashing

**Status:** Researching <!-- Researching / Recommending / Decided / Deferred -->
**Owner:** Rovin  ·  **Date:** 2026-06-27

## Question
How should pandex **traverse** filesystems, **detect changes** for surgical re-scans, and **hash** files for identity/dedup?

## Context & constraints
- Fast recursive scans of **huge trees**; cross-platform; low overhead on low-end devices.
- **Surgical re-scans:** detect what changed rather than rescanning everything.
- Content hashing for **file identity / dedup**.
- Pluggable per [`storage-connectors.md`](storage-connectors.md) (local is one Source among many).
- Permissive deps only.

## Options

### Directory traversal
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **ignore** | Parallel walk (ripgrep's) | Parallel (rayon); respects `.gitignore` (toggle **off** to index everything); very active; Unlicense/MIT | More complex API; pulls rayon; thread count not easily bounded |
| **walkdir** | Sequential walk | Simple, battle-tested, minimal deps; Unlicense/MIT | Single-threaded; no ignore-file support |
| jwalk | Parallel walk | Parallel; optional sorting; MIT | No releases since Dec 2022 (dormant) |

### Change detection / watching
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **notify** + `notify-debouncer-full` | Cross-platform FS events | De-facto standard; OS-native backends (inotify/FSEvents/ReadDirectoryChangesW) + `PollWatcher` fallback; debouncer merges noisy events; core CC0-1.0, debouncer MIT/Apache | **Linux inotify watch limits** on big trees; **network FS emits no events** → must fall back to mtime/size polling |

### Content hashing
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **blake3** | Fast cryptographic hash | Fastest crypto-grade hash; `rayon` parallel for big files; SIMD; CC0/Apache | Newer than SHA-2; C/ASM in build |
| xxhash-rust / twox-hash | Fast non-crypto (XXH3) | ~10 GB/s; tiny; BSL-1.0 (Boost) / MIT | **Non-cryptographic** — no adversarial collision resistance |
| sha2 | SHA-256 family | Interop standard (S3 etc.); audited; MIT/Apache | ~3–5× slower than blake3 |
| ~~seahash~~ | Non-crypto | Unmaintained since 2021 → skip |

> License note: `notify`'s core is **CC0-1.0** (public-domain dedication) and `xxhash-rust` is **BSL-1.0 = Boost Software License** (not the Business Source License) — both permissive and safe here.

## Recommendation
Scan with **ignore** (parallel, maintained, ripgrep-proven), calling `standard_filters(false)` when pandex must index files that `.gitignore` would otherwise hide; keep **walkdir** in mind for simple sequential cases. Detect changes with **notify** + **notify-debouncer-full**, with a **mandatory fallback to mtime+size (+inode) polling** for network filesystems and when Linux inotify watch limits are hit — that same snapshot-diff powers periodic **surgical re-scans**. Use **blake3** for file identity/dedup (fastest cryptographic hash, parallel on large files), reserving **sha2/SHA-256** for external interop (e.g. S3). A non-cryptographic **XXH3** (`twox-hash`) is a fine cheap *change-detection* fingerprint if cryptographic strength isn't required there. Proposal, not a lock.

## Open questions
- Event-driven **watch** vs periodic **poll** as the default per source type (local SSD vs network vs cloud)?
- Linux inotify watch-limit strategy (watch top-level dirs only; auto-fall back to poll on `MaxFilesWatch`).
- **One hash or two?** blake3 for both identity and change-detection, or blake3 (identity) + cheap XXH3 (quick change check)?
- `notify` v9 (RC; adds a tokio feature) — wait for stable or start on v8? (cross-ref [`async-runtime.md`](async-runtime.md))

## References
- https://github.com/BurntSushi/ripgrep/tree/master/crates/ignore · https://github.com/BurntSushi/walkdir
- https://github.com/notify-rs/notify
- https://github.com/BLAKE3-team/BLAKE3 · https://github.com/shepmaster/twox-hash · https://github.com/RustCrypto/hashes (sha2)
