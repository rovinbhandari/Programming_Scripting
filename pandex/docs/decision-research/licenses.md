# Decision research: License

**Status:** Decided — PolyForm Noncommercial 1.0.0 (logged in [`../architecture.md`](../architecture.md))
**Owner:** Rovin  ·  **Date:** 2026-06-27

## Question
Which license should pandex carry — one that lets us keep building on open-source libraries, yet stops others from taking pandex or using it commercially without our permission?

## Context & constraints
- **Requirement A:** we must stay free to depend on open-source libraries and tools.
- **Requirement B:** others may not commercially use or redistribute pandex without permission (noncommercial use and sharing are acceptable).
- **Key implication:** requirement B is incompatible with *open source* — every OSI license (MIT, Apache, GPL, **and** AGPL) lets anyone use the software commercially. So pandex must be **source-available**, not open source.
- pandex **leans Rust**, whose crates are almost all MIT/Apache — so requirement A is easy, as long as we avoid copyleft (GPL/AGPL) *dependencies* that would force pandex open.
- The author keeps full copyright either way, and can sell commercial licenses or relicense later.

## Options
Options that fail requirement B are struck through (whether open-source or source-available).

| Option | What others may do | Fits A | Fits B |
|--------|--------------------|:---:|:---:|
| ~~MIT / Apache-2.0~~ | Anything, including commercial. | ✅ | ❌ |
| ~~AGPL-3.0~~ | Anything incl. commercial, but must share source. | ✅ | ❌ |
| **PolyForm Noncommercial 1.0.0** | Use, modify, share — **noncommercial only**; commercial needs your permission. | ✅ | ✅ |
| **Business Source License 1.1** | Use/modify, but **no commercial/production use** until a "change date", then it auto-converts to an OSS license. | ✅ | ✅ (time-boxed) |
| ~~Functional Source License 1.1~~ | Any use **except competing** (internal and non-competing commercial use OK); each version auto-converts to Apache-2.0/MIT after 2 years. | ✅ | ❌ (only blocks competitors) |
| **Proprietary / All Rights Reserved** | Nothing without explicit permission (source visible, no rights granted). | ✅ | ✅ (maximal) |

## Recommendation
**PolyForm Noncommercial 1.0.0** — a clean, modern, source-available license: people may read, use, and improve pandex for noncommercial purposes, while all commercial rights stay with you and anyone wanting commercial use must ask. It satisfies both requirements and still invites a community.
- Step **stricter** to **Proprietary / All Rights Reserved** (simply ship no OSS license) if you don't want others using it even noncommercially without asking.
- Choose **BUSL 1.1** instead if you want pandex to *become* open source automatically after a few years.
- Consider **FSL-1.1** only if the goal later shifts to *wide adoption + eventually open*: it permits all non-competing commercial use and auto-converts to Apache-2.0/MIT after 2 years — so it blocks competitors, not commercial use, and fails requirement B as stated today.

Trade-off to accept: all of these mean pandex is **not open source**, so it forgoes OSS-only perks (some free CI tiers, distro inclusion, open-licensed contributions).

## Compatibility & reversibility
- **GPL/AGPL *libraries* are off-limits — but that's inherent to blocking commercial use, not a PolyForm quirk.** GPL/AGPL guarantee downstream commercial freedom and forbid adding a "noncommercial" restriction, so they can't combine with *any* commercial-restricting license.
- **Low risk in practice:** the Rust toolchain and crates.io are overwhelmingly MIT/Apache-2.0; GPL/AGPL crates are rare, so requirement A holds easily.
- **Escape hatches if ever needed:** invoke a GPL *tool* as a separate process/CLI (copyleft generally doesn't cross an arm's-length boundary); use an **LGPL** library via dynamic linking; or buy a commercial license for a dual-licensed library.
- **Reversibility:** the author owns the copyright, so future versions can be relicensed at will. Restrictive → permissive is the easy, safe direction; permissive → restrictive is not (you can't un-release an MIT version). Starting with PolyForm Noncommercial protects commercial rights now and keeps every option open.

## Open questions
- _Resolved 2026-06-27:_ **PolyForm Noncommercial 1.0.0**, copyright **Rovin Bhandari, 2026**. None remaining.

## References
- https://polyformproject.org/licenses/noncommercial/1.0.0/ — PolyForm Noncommercial text.
- https://mariadb.com/bsl11/ — Business Source License 1.1.
- https://fsl.software/ — Functional Source License 1.1 (FSL-1.1-ALv2 / FSL-1.1-MIT).
- https://choosealicense.com/no-permission/ — what "no license / all rights reserved" means.
- https://opensource.org/osd — why open source can't bar commercial use (criterion 6).
