# Decision research: Observability (logging, metrics, tracing)

**Status:** Researching <!-- Researching / Recommending / Decided / Deferred -->
**Owner:** Rovin  ·  **Date:** 2026-06-27

## Question
What telemetry stack — structured logging/tracing, metrics, and (optional) distributed tracing — should pandex use, and how do we keep it **near-zero-cost when disabled**?

## Context & constraints
- **Minimal & modular:** telemetry must add ~nothing when off; **OTLP export off by default**.
- Structured **spans** around scan / enrich / search; **async** pipeline → needs async-aware context.
- Cross-platform; permissive deps only.
- Should subsume third-party `log::*` output rather than run two systems.

## Options

### Logging & tracing
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **tracing** (+ `tracing-subscriber`, `tracing-appender`) | Structured spans + events | De-facto async standard; **compiles out** when disabled (`max_level_*`); `#[instrument]`; captures `log` via `tracing-log`; OTel bridge; MIT | Pre-1.0; `Layer` API has a learning curve |
| log (+ `env_logger`/`fern`) | Classic facade | Universal, minimal; MIT/Apache | String-only; no spans/structure/async/OTLP |
| slog | Pre-tracing structured logging | Mature; MPL/MIT/Apache (permissive) | Its own README recommends **tracing** instead; no OTLP |

### Metrics
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **metrics** + `metrics-exporter-prometheus` | Facade + optional Prometheus | Zero-cost with no recorder installed; swap backend at app level; MIT | Pre-1.0; ecosystem must share a version |
| prometheus (tikv) | Direct Prometheus instrumentation | Battle-tested at TiKV scale; Apache | No facade (locked to Prometheus); `protobuf` default; process metrics Linux-only |

### Distributed tracing (OpenTelemetry)
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **opentelemetry_sdk** + `opentelemetry-otlp` + `tracing-opentelemetry` | OTLP export bridge | Export to Grafana/Jaeger/Tempo/Honeycomb; metrics API **stable**; Apache/MIT | Traces API still **Beta**; ~4 crates must move in lockstep; heavy deps |

### Async diagnostics (dev-only)
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| console-subscriber / tokio-console | Live Tokio task debugger | Real-time task/poll/wake introspection — ideal for the enrichment scheduler; MIT | Requires `--cfg tokio_unstable`; dev-only, not production |

## Recommendation
**Core (always on):** `tracing` + `tracing-subscriber` (`fmt` + `EnvFilter`) + `tracing-appender` (non-blocking file writer), with `tracing-log` to absorb dependencies' `log::*` output. Use the `max_level_*` / `release_max_level_*` features so disabled instrumentation **compiles to nothing**. **Behind off-by-default cargo features:** the `metrics` facade and the OTLP stack (`tracing-opentelemetry` + `opentelemetry_sdk` + `opentelemetry-otlp`) — crucially, the `tracing` call-sites don't change between modes, only the subscriber does. Keep `tokio-console` as a `cfg`-gated **dev** aid. Proposal, not a lock.

## Open questions
- Adopt the OTel stack now (accept Beta traces API + 4-crate lockstep) or defer until a collector is actually needed?
- `metrics` facade vs direct `prometheus` — do we want backend-swap flexibility?
- Default release log format: human-readable `fmt` vs JSON?
- Which spans/metrics are the canonical ones (scan throughput, enrich queue depth, query latency)? — ties to [`benchmarking.md`](benchmarking.md).

## References
- https://github.com/tokio-rs/tracing · https://crates.io/crates/tracing-subscriber · https://crates.io/crates/tracing-appender
- https://github.com/metrics-rs/metrics · https://github.com/tikv/rust-prometheus
- https://github.com/open-telemetry/opentelemetry-rust · https://crates.io/crates/tracing-opentelemetry
- https://github.com/tokio-rs/console — tokio-console.
