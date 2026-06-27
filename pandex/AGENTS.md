# pandex — agent guide
pandex (pan-index) builds one queryable index of data files scattered across many PCs, VMs, and online stores.
It is the real-world target the `../Rust` learning track compounds toward — the "file indexer" end goal.
Our mascot is an omniscient Red Panda 🔥🐼🔥 — red for Rust, panda for pand-ex — who has (eventually) read every file so you don't have to.

## You MUST
- Ask, don't assume — when multiple choices exist or you're in doubt, surface them and ask.
- Record overview and key decisions in `docs/architecture.md`; prefer editing/subtracting over appending, since everything is versioned.
- Keep that overview understandable at a glance, linking out to detailed notes instead of inlining them.
- Grow `docs/` as a tree — abstract at the root, granular at the leaves — so a high-capability model can build a whole area from the top with autonomy, while leaf specs let a cheaper model build feature-by-feature; push new detail toward the leaves.
- Favour less code and pluggable, modular functionality over clever density.
- When touching code, look holistically for things to delete or refactor to cut total complexity.
- Verify build, test, and a rubber-duck review before committing or calling work done.
- Update `README.md` and `TODO.md` whenever key details change or work goes on the backburner.
- One commit = one holistic feature or significant bugfix; note small accompanying changes in the body.
- Never commit real data files; small synthetic test fixtures are fine.
- Keep it fun, and teach as you go — explain the *why*, offer alternatives, and drop the odd trivia.

## Performance bar (non-negotiable)
- pandex must run well across a wide range of devices and operating systems.
- Prefer device-usage troughs for heavy work, and process scanned files asynchronously for embeddings and keyword extraction.
- Keep data and schema versioned, and support surgical re-scans rather than full rebuilds.
- Measure with telemetry and benchmarks, document the numbers, then revisit the slow parts.

## Teaching style
- Relate new ideas to known ground: Tier 1 C# (primary analogy), Tier 2 C/Python (secondary), then the plain concept.
- Use mermaid or svg diagrams when a picture helps, kept next to what they explain.
- Ground claims and research in well-known resources and link them in notes and/or cite them in chat.

## Files & layout
- `README.md` — what pandex is and its status (hard cap: 100 sentences).
- `AGENTS.md` — this rules file (hard cap: 50 sentences).
- `TODO.md` — near-term and backburnered tasks.
- `PLAN.md` — the living plan of work and decisions in flight.
- `docs/architecture.md` — the at-a-glance overview and decision log, linking to deeper notes under `docs/`.
- `docs/decision-research/` — option comparisons (from `template.md`) that feed decisions before they land in `architecture.md`.

## Commits
- Follow the repo commit skill in `../.agents/skills/commit`: subject <= 80 chars, up to 5 bullets <= 120 chars, plus the Co-authored-by trailer.
- Run its `check-commit.ps1` (or the message and changes scripts) before pushing.
