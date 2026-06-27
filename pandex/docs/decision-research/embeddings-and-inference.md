# Decision research: Embeddings & model inference

**Status:** Researching <!-- Researching / Recommending / Decided / Deferred -->
**Owner:** Rovin  ·  **Date:** 2026-06-27

## Question
How should pandex compute **text embeddings** (and run small **LLMs** for RAG) — on-device by default, with an optional hosted path — behind a pluggable provider interface?

## Context & constraints
- **Privacy-first:** on-device is the default; any hosted call **sends file content off-device** and must be explicit opt-in.
- Must run **CPU-only on diverse / low-end** devices; GPU is a bonus, never a requirement.
- **Async background enrichment** during idle troughs — embedding/inference happens off the interactive path.
- **Minimal build pain** across OSes; **flag heavy native deps** (libtorch, CUDA) and **copyleft**.
- **Pluggable:** hide behind an `Embedder` (and optional `Generator`) trait so the backend can be swapped.

## Options

### On-device runtimes
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **fastembed-rs** (on `ort`) | Turnkey text → vector | 4-line API; bundled **quantized CPU** models (BGE-small INT8, 384-d); auto-download + cache; Apache; low build pain | `ort` is **2.0 RC**; first-run download; single maintainer |
| **candle** | HuggingFace pure-Rust ML | Pure Rust on CPU (no C++); HF model zoo; GGUF quant; MIT/Apache | v0.x API churn; you wire tokenizer/weights; CPU slower than llama.cpp |
| ort | ONNX Runtime binding | Runs any ONNX model; **auto-downloads** prebuilt binary; huge exec-provider ecosystem; MIT/Apache | Wraps a C++ binary (not pure Rust); 2.0 RC |
| tract | Pure-Rust ONNX/TF inference | **Zero native deps**; MIT/Apache | CPU-only; newest ONNX ops lag; smaller community |
| llama-cpp-2 | `llama.cpp` binding | Best CPU **GGUF** perf; does embeddings **and** LLM; MIT/Apache (llama.cpp MIT) | C++/CMake build; low-level API |
| mistral.rs | candle-based engine | Embeddings + LLM + OpenAI server; ISQ/UQFF quant; MIT | Large API; GPU-focused; recent crate |
| burn | Pluggable DL framework | `ndarray` pure-Rust CPU, `wgpu` GPU; MIT/Apache | Fewer ready LLMs; ONNX import is codegen; `tch` backend pulls libtorch ⚠️ |
| rust-bert | HF-transformers port | Broad NLP pipelines; Apache | **Default libtorch (~2–3 GB)** ⚠️; ONNX mode is extra steps; activity slowed |

### Subprocess servers (pandex shells out over HTTP)
| Option | Summary | Pros | Cons |
|--------|---------|------|------|
| **Ollama** | Local LLM daemon | MIT; `/api/embed`; user-managed; **licensing isolation**; one-command install | External install; IPC/startup latency |
| llama.cpp server | OpenAI-compatible server | Most flexible GGUF; MIT | No polished installer; harder to distribute |
| ~~LM Studio~~ | GUI app + REST API | Nice UX for exploring models | **Proprietary, noncommercial-only** → avoid as a required dep |

### Hosted APIs (explicit opt-in — data leaves the device)
| Provider | Embedding model | Notes |
|--------|---------|------|
| **OpenAI** | `text-embedding-3-small` (1536-d, truncatable) | Strong cost/quality; `async_openai` (MIT); Azure variant adds data-residency |
| Voyage AI | `voyage-4*` (configurable dims) | Strong RAG quality (used by Anthropic) |
| Cohere | `embed-*-v3.0` / `v4.0` (1024–1536-d) | Multilingual; free tier |
| Google Gemini | `gemini-embedding-*` | Multimodal; free tier; dims unverified |
| Mistral | `mistral-embed` (1024-d) | OpenAI-compatible endpoint |

_Hosted dimensions above are commonly cited but several were **unverified from live docs** — confirm before pinning a vector-store schema._

## Recommendation
Default to **fastembed-rs** (ONNX via `ort`) for on-device embeddings — turnkey, CPU-friendly, quantized small models, permissive — behind an `Embedder` trait. Offer an optional **subprocess provider (Ollama, MIT)** as the power-user path for richer models and small-LLM RAG, and an optional **hosted provider** (OpenAI/Voyage/…) behind an explicit `--hosted` opt-in with a clear privacy disclosure. Keep pure-Rust **candle**/**tract** noted as the zero-C++ fallback if `ort`'s RC status or the prebuilt-binary download becomes a problem. Avoid **rust-bert**'s default libtorch and **LM Studio**'s proprietary dep. Proposal, not a lock — pin `ort` and test on all three OSes.

## Open questions
- `ort` is pre-1.0 (RC): accept pin-and-test risk, or start pure-Rust (candle/tract)?
- Which **default embedding model + dimensionality**? (Sets the vector-store schema in [`index-store.md`](index-store.md).)
- **In-process vs subprocess** as the default — build simplicity vs licensing isolation?
- Do we need an LLM at all for M3, or do embeddings + classical keywords ([`keyword-extraction.md`](keyword-extraction.md)) suffice first?

## References
- https://github.com/Anush008/fastembed-rs · https://crates.io/crates/fastembed
- https://github.com/huggingface/candle · https://github.com/pykeio/ort · https://github.com/sonos/tract
- https://github.com/utilityai/llama-cpp-rs (llama-cpp-2) · https://github.com/EricLBuehler/mistral.rs · https://github.com/tracel-ai/burn
- https://github.com/ollama/ollama · https://github.com/ggml-org/llama.cpp
- https://platform.openai.com/docs/guides/embeddings · https://docs.voyageai.com · https://docs.cohere.com/docs/cohere-embed
- https://crates.io/crates/async_openai — OpenAI-compatible Rust client.
