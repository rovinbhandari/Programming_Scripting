# Decision research: Benchmarking & profiling

**Status:** Researching <!-- Researching / Recommending / Decided / Deferred -->
**Owner:** Rovin  ·  **Date:** 2026-06-27

## Question
How should pandex **measure and track performance** — microbenchmarks, whole-CLI benchmarks, and profiling — in a CI-stable, cross-platform way?

## Context & constraints
- We **obsess over performance**: document it, then revisit the slow parts (paired with [`observability.md`](observability.md)).
- **CI-stable** measurements; **cross-platform incl. Windows**.
- Runs on diverse / low-end hardware → need both micro (algorithmic) and macro (real-CLI, cold/warm cache) views.
- Permissive deps; benchmark/profiling tools may be `cargo install`ed (not runtime deps).

## Options

### Microbenchmarks
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **criterion** | Statistical microbench + baselines | Gold standard; stored baselines → regression detection; async support; Apache/MIT | Wall-clock noisy on shared CI; heavy default deps; needs Rust **1.86+**; org migration in progress |
| **divan** | Attribute-based microbench | Clean ergonomics; lighter deps; MIT/Apache | Much smaller adoption; no baseline file / HTML; single maintainer |
| **iai-callgrind** | Instruction counts via Valgrind | **Deterministic, CI-stable to one instruction**; MIT/Apache | **Linux/macOS only** (no Windows CI); 20–50× slower; not for I/O |
| ~~iai~~ | Predecessor | — | Abandoned (2021) → use iai-callgrind |

### Whole-CLI / macro
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **hyperfine** | CLI wall-clock benchmarking | Warmup (cold/warm cache), params, CSV/JSON/MD export; fully cross-platform; MIT/Apache | External tool; wall-clock noise inherent to macro timing |

### Profiling
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **samply** | Sampling profiler, Firefox-Profiler UI | **Truly cross-platform incl. Windows** (ETW); interactive; on- and off-CPU; MIT/Apache | Pre-1.0; single maintainer |
| **dhat** | Heap / allocation profiler | Cross-platform in-process mode; finds alloc hotspots; MIT/Apache | Somewhat dormant (feature-complete) |
| cargo-flamegraph | SVG flamegraph | Simple; Linux `perf` / macOS `xctrace` / Windows `blondie`; MIT/Apache | Windows backend less mature; static SVG; linker flag on recent Rust+Linux |
| pprof-rs | In-process CPU profiler | Integrates with criterion; Apache | **Linux/macOS only** (SIGPROF) |
| tracing-flame | Span-time flamegraph | Unique span-time view; MIT | No crates.io release since 2021; only covers instrumented spans |

## Recommendation
**Microbenchmarks:** `criterion` (baselines + regression detection via `cargo bench`) as the default — or `divan` if its lighter ergonomics are preferred; they aren't mutually exclusive. Add `iai-callgrind` in a **Linux-only CI job** for deterministic instruction-count regression gates on algorithmic hot paths (scan loop, similarity search). **Whole-CLI:** `hyperfine` (installed, not a dep) for cold/warm-cache timing of `pandex index` / `pandex search`. **Profiling:** `samply` as the primary cross-platform (incl. Windows) interactive profiler, `dhat` for allocations, `cargo-flamegraph` as an SVG alternative. Document results so the slow parts are visible and re-checkable. Proposal, not a lock.

## Open questions
- `criterion` vs `divan` as the primary harness (criterion's MSRV 1.86 is a constraint).
- Is a Linux-only `iai-callgrind` gate worth the maintenance vs wall-clock `criterion`?
- What are the **performance budgets** per operation (scan files/sec, query p95 latency, enrich throughput)?
- Where do we store benchmark results over time so regressions are visible across releases?

## References
- https://github.com/criterion-rs/criterion.rs · https://github.com/nvzqz/divan · https://github.com/iai-callgrind/iai-callgrind
- https://github.com/sharkdp/hyperfine
- https://github.com/mstange/samply · https://github.com/flamegraph-rs/flamegraph · https://github.com/tikv/pprof-rs · https://github.com/nnethercote/dhat-rs
