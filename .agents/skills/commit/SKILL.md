---
name: commit
description: Create a clean, policy-compliant git commit, and audit existing commits. Use whenever you are about to commit in this repository, when the user asks to "commit", or when asked to check a commit. It enforces the message format (subject <= 80 characters, then up to 5 bullets of <= 120 characters each, plus the Co-authored-by trailer) and runs safety checks for secrets, local filesystem paths (Windows and Linux), personal data, .gitignore violations, and the commit-related rules in any applicable AGENTS.md. By default it splits unrelated changes into separate commits per logical change, or makes a single commit when the user says "all", "as one", or "together". The bundled scripts can be run directly, against staged changes or against any existing commit.
compatibility: Requires git and PowerShell 7.4+ (pwsh). The scripts are optional accelerators; if pwsh is unavailable, perform the equivalent checks by hand.
metadata:
  scope: repository-wide
---

# Commit

Create small, reviewable, policy-compliant commits — and audit existing ones. The scripts in
this skill's `scripts/` directory are the heart of the skill; you (or Copilot) can run them
directly at any time, against the staged changes or against any existing commit.

## Scripts

All live in `scripts/` and need nothing beyond `git` + `pwsh`. Each exits `0` when clean,
`1` on a blocking issue, `2` on bad usage, and prints blocking issues (`X`) and warnings
(`!`). Resolve every `X`; confirm each `!` is intentional.

- `check-message.ps1` — validate a commit message's format.
  - `pwsh .agents/skills/commit/scripts/check-message.ps1 <message-file>`
  - `pwsh .agents/skills/commit/scripts/check-message.ps1 -Commit HEAD`
- `check-changes.ps1` — scan changes for secrets, local filesystem paths (Windows and Linux),
  and force-added `.gitignored` files.
  - `pwsh .agents/skills/commit/scripts/check-changes.ps1`               # staged (default)
  - `pwsh .agents/skills/commit/scripts/check-changes.ps1 -Commit <sha>`
- `check-commit.ps1` — audit an existing commit in one shot (message + changes).
  - `pwsh .agents/skills/commit/scripts/check-commit.ps1 [<sha>]`        # default HEAD

## Message format

- Subject (first line): imperative mood, no trailing period, **<= 80 characters**.
- One blank line.
- Then **up to 5 bullets**, each starting with `- ` and **<= 120 characters**. Bullets are
  optional for trivial changes; one idea per bullet, no hard-wrapping.
- Trailers go last (after a blank line) and don't count toward the bullet limit. Always
  include, unless the user says otherwise:

  `Co-authored-by: Copilot <223556219+Copilot@users.noreply.github.com>`

## Grouping changes into commits

This is the main thing the skill adds on top of the scripts: decide **how many commits** to make.

- **Default — split by logical change.** When the working tree holds several unrelated changes
  (e.g. a feature, an unrelated fix, a docs tweak), make a **separate commit for each**: group
  the related files, then run the steps below once per group, staging only that group's files.
  A single logical change is naturally one commit.
- **Single commit on request.** If the user signals it with words like "all", "as one",
  "together", "in one", "one commit", or "squash", put everything in **one** commit.
- If the right split is unclear, ask before committing.

## Creating a commit

Do this once per commit group decided above.

1. **Stage deliberately.** Only the files for this one logical change; prefer explicit paths
   over `git add -A`. Confirm with `git diff --cached --stat`.
2. **Write the message** to a temp file and validate it with `check-message.ps1`.
3. **Scan the staged changes** with `check-changes.ps1`. Resolve blocking issues (unstage the
   file, edit out the value, or add a `.gitignore` rule) and confirm warnings.
4. **Judgment checks** the scripts can't fully automate:
   - Read `AGENTS.md` at the repo root and in every touched folder and honor each
     commit-related rule (e.g. "never commit real data", file/line caps, what stays out of
     git). `.github/copilot-instructions.md` and `.github/instructions/**` also apply.
   - No personal data: names, emails (other than the trailer), machine names, home paths.
   - No blatantly insecure code: hardcoded credentials, disabled TLS/cert verification,
     `eval` of untrusted input, command injection, etc.
   - Skim `git diff --cached` so the change contains only what you intend.
5. **Commit:** `git commit -F <message-file>`, then confirm with
   `git --no-pager log --oneline -1` and a clean `git status`.

## Auditing an existing commit

Run `check-commit.ps1 <sha>` (or no argument for HEAD) to validate the message and scan the
changes of a commit that already exists — useful before pushing or when reviewing history.

## Notes

- One logical change per commit.
- Do not rewrite published history (no `rebase` / force-push on shared branches) unless the
  user explicitly asks.
- To intentionally allow a flagged line (e.g. a pattern definition or a test fixture), put
  `commit-skill:allow` in a comment on that line; `check-changes.ps1` skips such lines.
- The scripts are accelerators, not gates: if `pwsh` is unavailable, perform the same checks
  by hand using the lists above.
