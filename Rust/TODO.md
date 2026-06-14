# Rust Learning — TODO

Future-looking tasks for the learning track. Keep this **<= 100 lines**. (Day-to-day exercise progress lives in `Sequence.md`; this is the "what's next / don't forget" board.)

Legend: ⬛ todo · 🔄 in progress · ✅ done

## Now / next
- 🔄 Level 1 (fundamentals) — specs handed over; awaiting solutions to review.
- ⬛ Review each Level 1 solution: check the **code** and the **understanding-in-comments**.
- ⬛ After Level 1 is solid, design & drop in Level 2 (ownership & borrowing).

## Teaching artifacts to add as we go
- ⬛ Concept note + diagram for **ownership/move** (stack vs heap) before Level 2.
- ⬛ Concept note + diagram for **borrow rules** (one `&mut` XOR many `&`).
- ⬛ Per-topic `.md` notes with C# (tier 1) and C/Python (tier 2) analogies.
- ⬛ Track recurring mistakes / shaky concepts here so we can revisit them.

## Milestones
- ⬛ Decide the **graduate-to-Cargo** moment (target: Level 5 guessing game / `rand`).
- ⬛ Once on Cargo: wire up `rustfmt` + `clippy`; add a few `#[test]`s.
- ⬛ At Cargo graduation: revert the Cargo-less rust-analyzer workarounds in `.vscode/settings.json` — flip `rust-analyzer.checkOnSave` back to `true` and drop the `linkedProjects` list (RA then auto-discovers the workspace).

## Backlog (sequence later in Sequence.md "Beyond")
- ⬛ Modules & crate organization.
- ⬛ Smart pointers: `Box`, `Rc`, `RefCell`.
- ⬛ Error-handling crates: `anyhow`, `thiserror`.
- ⬛ Concurrency: threads + channels; later `async`/`await`.
- ⬛ A slightly bigger capstone CLI once Levels 1–5 are done.

## Housekeeping
- ⬛ Keep `Sequence.md` checkboxes in sync after every review.
- ⬛ Keep this file under 100 lines; prune done items into a short "Done" note.
