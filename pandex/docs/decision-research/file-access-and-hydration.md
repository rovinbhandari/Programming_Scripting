# Decision research: File access & hydration (local / external / cloud / placeholder)

**Status:** Researching <!-- Researching / Recommending / Decided / Deferred -->
**Owner:** Rovin  ·  **Date:** 2026-06-27

## Question
How should pandex **read** file content across four access scenarios — fully-local disk, external/removable disk, cloud-only (no local copy), and **shallow cloud placeholders** (OneDrive / iCloud "dataless" stubs) — **without accidentally hydrating** (downloading) a placeholder, and without mistaking an unplugged drive for a deletion?

## Context & constraints
- **The cardinal rule:** a surprise download costs the user bandwidth *and* money. **Never touch a file's data until we know it is local.** Detection must be **attribute-only** (no `open`).
- **Offline ≠ deleted:** an unplugged volume must mark its files unavailable, never removed from the index.
- Cross-platform, low-end devices → prefer **pure-Rust, permissive, zero/low native-dep** crates; flag exceptions.
- Reuses connectors ([`storage-connectors.md`](storage-connectors.md)), scan + identity + hashing ([`fs-scan-and-watch.md`](fs-scan-and-watch.md)), idle-only deep reads ([`async-runtime.md`](async-runtime.md)); feeds type detection ([`file-types-and-metadata.md`](file-types-and-metadata.md)) via cheap header bytes.

## The materialization model (the heart of this note)
A single enum gates every read. **Only `Present` may be opened/mmap'd locally.**

| State | Meaning | Safe action |
|-------|---------|-------------|
| **Present** | Content fully local | `stat` → `header_bytes` → (Tier 2) full read / mmap |
| **PlaceholderDehydrated** | Local stub, data not local (OneDrive/iCloud) | **attribute check only**; fetch via cloud connector — **never `open`** |
| **RemoteOnly** | Exists only in cloud (no local stub) | `stat`/HEAD (no egress); `range(0..512)` sniff; full GET deferred |
| **OfflineUnavailable** | Volume/mount not connected | nothing — keep indexed, reconcile on reconnect |

## Options

### 1 — Local-disk reads
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **std `BufReader` + header read** | Buffered sequential; read first 512 B for sniff | Zero deps, always-correct, safe on network FS; ideal Tier 0/1 | Double-copy for huge files |
| **memmap2** | Zero-copy `&[u8]` over the file | Fastest for ≥1 MB multi-pass/hashing (`blake3` has an `mmap` feature) | `unsafe` (truncation → SIGBUS/UB); **⚠️ mmap of a placeholder triggers hydration**; bad on network FS |
| **blake3** (hash) | Parallel hash, `mmap`+`rayon` features | CC0/Apache; fastest; for content identity/dedup | — |
| **sha2** (hash) | Streaming SHA-256 | MIT/Apache; interop where SHA-256 required | Slower than blake3 |

### 2 — External / removable volumes (identity & availability)
| Concern | Crate / API | License | Note |
|---------|-------------|---------|------|
| Disk enumeration | **sysinfo** (`is_removable`, `mount_point`, `available_space`) | MIT | best-effort removable flag |
| Stable volume id (Win) | `std::os::windows::fs::MetadataExt::volume_serial_number()` | std | zero deps; pair serial **+ label** (serial not globally unique) |
| Stable volume id (Unix) | **rustix** `statfs().f_fsid` / `nix` / `libc` (`st_dev`) | Apache/MIT · MIT | `st_dev` session-only; `f_fsid` best persistent option |

Record `(volume_key, label, mount_point@scan)` per volume and `(volume_key, rel_path, ino/file_index, size, mtime)` per file; absent volume → `OfflineUnavailable`.

### 3 — Cloud-only (no local copy)
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **opendal** `stat()` / `read_with().range(0..512)` | Unified async store | Apache-2.0; widest breadth incl. **Dropbox/OneDrive/GDrive**; HEAD/stat = no egress (minor per-request charge), partial GET cheap | pre-1.0; audit transitive OAuth deps via `cargo deny` |
| **object_store** `head()` / `get_range()` / `get_ranges()` | Arrow-ecosystem store | MIT/Apache; production-hardened; vectored ranges | S3/GCS/Azure only |

Cost ladder: `stat`/HEAD (no egress; minor per-request charge) → `range(0..512)` (one GET, negligible egress) → full GET (**Tier 2 only**, explicit).

### 4 — Placeholder / dehydrated detection (no hydration) — **critical**
| OS | Detection (attribute-only) | Crate | Verified |
|----|----------------------------|-------|----------|
| **Windows** | **Attribute-only, no open:** read `WIN32_FIND_DATA.dwFileAttributes` from the scan's directory enumeration, or `GetFileAttributesExW` — `OFFLINE` / `RECALL_ON_DATA_ACCESS` (0x400000) ⇒ dehydrated; `RECALL_ON_OPEN` surfaces only in enumeration; cloud reparse tag `IO_REPARSE_TAG_CLOUD*` from `dwReserved0`. **Avoid `std::fs::metadata`** — it opens a zero-access handle (verified in std), unsafe for `RECALL_ON_OPEN`. | **windows-sys**/**windows** (MIT) for `GetFileAttributesExW`/`FindFirstFileW`/Cloud Filter `CfGetPlaceholderState*`; `std` only once `Present` | MS Learn: HSM minifilters MUST set `RECALL_ON_DATA_ACCESS`; `GetFileAttributesEx`/enumeration read it without recall |
| **macOS** | `lstat().st_flags & SF_DATALESS` (0x40000000, 10.15+); `.name.ext.icloud` stub pattern; xattr `com.apple.cloud.filestate` | **libc**/**rustix**/**nix** (MIT/Apache) · **xattr** (MIT/Apache) | `lstat`/xattr are pure metadata — no open |
| **Linux** | **No standard.** Sync clients fully materialise or omit. Heuristic: sync-root path patterns (`~/Dropbox`, `~/OneDrive`); treat readable files as `Present` | libc/rustix/nix | documented gap |

_`SF_DATALESS` may be absent from `libc`; define `const SF_DATALESS: u32 = 0x4000_0000;` under `#[cfg(target_os="macos")]`._

## Recommendation
Make a **`MaterializationState` enum + `BlobSource` trait** (`stat` / `materialization_state` / `header_bytes(n)` / `content_stream`) the single choke-point for all reads, so the **cardinal rule is enforced in one place**: *no `open`/`read`/`mmap` until state is `Present`.* **Defaults:** local reads via std `BufReader` + a 512 B header sniff for Tiers 0–1; **`memmap2` only for confirmed-`Present` files ≥1 MB** (large-file hashing with `blake3`'s `mmap` feature); never mmap placeholders or network filesystems. **Volume identity:** `volume_serial_number()` (Windows, zero-dep) / `rustix statfs().f_fsid` (Unix) + label, with `sysinfo` for enumeration; absent volume ⇒ `OfflineUnavailable`, never deleted. **Cloud:** `opendal` as the default connector (breadth incl. OneDrive/Dropbox/GDrive), `object_store` available for S3/GCS/Azure; always `stat`→`range(0..512)`, full GET only in Tier 2. **Placeholders:** attribute-only detection per the table — Windows `RECALL_ON_DATA_ACCESS`/`RECALL_ON_OPEN`/`OFFLINE` via no-open `GetFileAttributesExW`/directory enumeration (**not** `std::fs::metadata`, which opens a zero-access handle), macOS `SF_DATALESS` via `lstat`; Linux best-effort by path. To Tier-1-sniff a placeholder, fetch `range(0..512)` through the **cloud** connector using the file's cloud identity, **not** the local stub. All crates here are permissive (no GPL/AGPL); the only native-dep escalations are optional. Proposal, not a lock.

## Open questions
- Tie `PlaceholderDehydrated.cloud_identity` to which connector key (reparse tag → provider mapping)? How do we resolve a Windows OneDrive stub to its `opendal` operator?
- Do we ever **auto-hydrate** placeholders for Tier 2 (with explicit user consent + metered-network guard), or strictly index metadata only?
- Linux: ship sync-root heuristics (path patterns) in config, or skip placeholder logic entirely there?
- `memmap2` truncation-`SIGBUS` safety — wrap reads in a guard, or restrict mmap to read-only snapshots?
- Audit `opendal` transitive OAuth deps with `cargo deny` before adopting (see [`licenses.md`](licenses.md)).

## References
- Windows file attributes — https://learn.microsoft.com/windows/win32/fileio/file-attribute-constants
- Reparse tags — https://learn.microsoft.com/windows/win32/fileio/reparse-point-tags · Cloud Filter state — https://learn.microsoft.com/windows/win32/api/cfapi/ne-cfapi-cf_placeholder_state
- Placeholder guidance (RECALL_ON_DATA_ACCESS MUST) — https://learn.microsoft.com/windows-hardware/drivers/ifs/placeholders_guidance
- std Windows `MetadataExt` — https://doc.rust-lang.org/std/os/windows/fs/trait.MetadataExt.html
- https://github.com/RazrFalcon/memmap2-rs · https://github.com/BLAKE3-team/BLAKE3 · https://github.com/bytecodealliance/rustix · https://github.com/Stebalien/xattr
- https://github.com/GuillaumeGomez/sysinfo · https://opendal.apache.org/ · https://github.com/apache/arrow-rs-object-store
