# Decision research: File types & metadata (tiered)

**Status:** Researching <!-- Researching / Recommending / Decided / Deferred -->
**Owner:** Rovin  ·  **Date:** 2026-06-27

## Question
Which file types should pandex support, what metadata should it capture per type, and which Rust crates detect types and extract metadata/content — organised as a **tiered scope** we can expand incrementally?

## Context & constraints
- **Metadata first, content later:** a cheap universal pass over *all* files (M2), then opt-in async content enrichment (M3).
- **Tiered scope** so the **min bar is universal** and expansion is incremental, not all-or-nothing.
- Cross-platform, low-end devices → prefer **pure-Rust, zero-native-dep, permissive** crates; **flag heavy native deps and copyleft**.
- **Pluggable:** there is **no Rust equivalent of Apache Tika**, so pandex must own a per-format `Extractor` dispatch behind a trait.
- Content hashing & file identity specifics live in [`fs-scan-and-watch.md`](fs-scan-and-watch.md); reading without side effects (placeholders/cloud) lives in [`file-access-and-hydration.md`](file-access-and-hydration.md).

## The tiering model (the heart of this note)
| Tier | What | When | Cost |
|------|------|------|------|
| **0 — min bar** | Filesystem metadata + extension hint; **no content read** | Every file, initial sweep | one `stat()` per file |
| **1 — cheap metadata** | Magic-byte type sniff + embedded headers/tags (EXIF, ID3, PDF info, Office `core.xml`) | Background scan | O(KB) header read |
| **2 — deep content** | Full text / OCR / transcription for keywords, embeddings, RAG | Async, idle-only ([`async-runtime.md`](async-runtime.md)) | O(file) + maybe a model |

## Options

### Type detection
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **infer** | Magic-byte sniff (~150 sigs) | `no_std`, tiny, simple; MIT; zero native deps | Can't tell DOCX from a plain ZIP; ~150 types |
| **file-format** | Magic + optional container peek | Distinguishes DOCX/XLSX/PPTX via `reader-zip`; 250+ formats; MIT/Apache | Slightly more I/O with depth readers |
| **mime_guess** | Extension → MIME | Zero I/O, instant, huge DB; MIT | Extension-only (spoofable) |
| mime | MIME *type* representation | Canonical interop type; MIT/Apache | Not a detector |
| ~~tree_magic_mini~~ | FreeDesktop MIME tree | Good text subtypes; MIT crate | ⚠️ `with-gpl-data` feature pulls **GPL-2.0** data → **never enable it** |
| ~~magic~~ | `libmagic` binding | Most thorough DB; permissive wrapper | ⚠️ Native `libmagic`; **no native Windows** → poor fit |

### Tier 0 — universal metadata (std only, no extra crate)
- `std::fs::Metadata`: size, `modified()`, type, read-only. `accessed()`/`created()` are unreliable cross-platform (Linux often lacks birth time; atime frequently disabled).
- **Stable file identity:** Unix `(dev, ino)` via `std::os::unix::fs::MetadataExt`; Windows `(volume_serial_number, file_index)` via `std::os::windows::fs::MetadataExt` — survives renames within a volume (lost across filesystems → fall back to content hash, see [`fs-scan-and-watch.md`](fs-scan-and-watch.md)). Note: the Windows id comes from a handle-opening `GetFileInformationByHandle`, so read it only **after** a file is confirmed `Present` — detect placeholders first ([`file-access-and-hydration.md`](file-access-and-hydration.md)).
- **Use `mtime` as the primary change signal**; treat birth time as optional enrichment; never rely on `atime`.

### Tier 1 — cheap embedded metadata (per family)
| Family | Crate(s) | License | Note |
|--------|----------|---------|------|
| Image dimensions | **imagesize** | MIT | Reads 10–64 bytes; no decode |
| Image EXIF | **kamadak-exif** (image) · **nom-exif** (image **+ video**) | BSD-2 · MIT | nom-exif unifies image+video metadata |
| Audio tags | **lofty** (all formats) · `id3` (MP3 only) | MIT/Apache · MIT | lofty = ID3/Vorbis/MP4/APE/… |
| Audio/video container | **symphonia** (probe-only) · `matroska` · `mp4` | **MPL-2.0** · MIT/Apache · MIT | symphonia MPL = weak, file-level copyleft — **acceptable**, doesn't infect pandex |
| PDF info/pages | **lopdf** · `pdf` | MIT | Info dict, page count, XMP |
| Office (docx/xlsx/pptx) | **zip** + `quick-xml` → `docProps/core.xml`; **calamine** for sheets | MIT | OOXML = ZIP+XML |
| Text encoding | **chardetng** + **encoding_rs** | Apache/MIT (+BSD-3 data) | Detect legacy encodings → UTF-8 |

### Tier 2 — deep content extraction (async, optional, feature-gated)
| Family | Crate(s) | License | Native-dep / risk |
|--------|----------|---------|-------------------|
| PDF text | **pdf-extract** (pure Rust) · `pdfium-render` (better) | MIT · MIT/Apache (pdfium binary BSD-3-Clause) | pdfium = ~20 MB binary per platform |
| Spreadsheet | **calamine** | MIT | ✅ pure Rust |
| DOCX | **docx-rs** | MIT | reader API less ergonomic |
| PPTX | `zip` + `quick-xml` (manual) | MIT | no dedicated crate |
| Image OCR | **ocrs + rten** (pure Rust) · `tesseract`/`leptess` (better) | MIT/Apache · permissive | ocrs needs ~30 MB model; tesseract needs libtesseract + lang data |
| Audio transcription | `whisper-rs` · candle-whisper | Unlicense/MIT · MIT/Apache | C++ build + 75 MB–2.9 GB models |

_Abandoned/avoid: `dotext` (2017), `docx` (2020). Pure-Rust, zero-native-dep options are preferred for the default build; everything with a heavy native dep stays **optional**._

## Recommendation
Adopt the **3-tier scope** as the project's expansion lever. **Tier 0 (min bar, ship first):** `std` metadata + the `(dev,ino)`/`(volume_serial,file_index)` identity key + a `mime_guess` extension hint — universal, one `stat()` per file. **Tier 1 (first expansion):** add `infer` (+ `file-format` `reader-zip` for OOXML), `imagesize`, `kamadak-exif`/`nom-exif`, `lofty`, `symphonia` probe-only, `lopdf`, `zip`+`calamine`, `chardetng`+`encoding_rs` — **all pure-Rust, permissive, zero native deps.** **Tier 2 (opt-in enrichment):** `pdf-extract`, `calamine`, `docx-rs`, `zip`+XML for PPTX, with `ocrs`+`rten` as the **pure-Rust OCR default** and `pdfium-render`/`tesseract`/`whisper-rs` as **feature-gated, never-mandatory** higher-quality options. Because no Rust "Tika" exists, define an **`Extractor` trait + type→extractor dispatch** as a first-party piece — this *is* the pluggability model for Tiers 1–2. **License guards:** never enable `tree_magic_mini`'s `with-gpl-data` (GPL-2.0); don't link/ship GPL-built FFmpeg (use `symphonia`/`matroska`/`mp4`); `symphonia`'s MPL-2.0 is fine. Proposal, not a lock.

## Open questions
- Which formats are in the **Tier-1 supported set for v1**, and the expansion order across families?
- **Extractor dispatch** design: a registry of per-format impls; how do (third-party?) extractors register?
- Default OCR/transcription: bundle pure-Rust `ocrs`/`rten` + small models, or leave OCR/audio entirely opt-in?
- Identity across **cross-filesystem moves** (inode/file-id lost) — rely on content hash from [`fs-scan-and-watch.md`](fs-scan-and-watch.md)?
- Record the **`symphonia` MPL-2.0** (and `nom-exif` `license-file=MIT`) compliance notes in [`licenses.md`](licenses.md)?

## References
- https://github.com/bojand/infer · https://github.com/mmalecot/file-format · https://github.com/abonander/mime_guess
- https://doc.rust-lang.org/std/os/windows/fs/trait.MetadataExt.html · https://doc.rust-lang.org/std/os/unix/fs/trait.MetadataExt.html
- https://github.com/kamadak/exif-rs · https://github.com/mindeng/nom-exif · https://github.com/Roughsketch/imagesize
- https://github.com/Serial-ATA/lofty-rs · https://github.com/pdeljanov/Symphonia · https://github.com/tafia/calamine · https://github.com/J-F-Liu/lopdf
- https://github.com/jrmuizel/pdf-extract · https://github.com/robertknight/ocrs · https://codeberg.org/tazz4843/whisper-rs
- Apache Tika (the missing Rust equivalent) — https://tika.apache.org/
