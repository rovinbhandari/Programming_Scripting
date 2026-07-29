✅ Organize the folders properly.
⬛ Include code from the semester work to this repo as well.
⬛ Align ScrApe's clipping with the Obsidian Web Clipper. See below.

## Aligning ScrApe with the Obsidian Web Clipper

Both clip the same links into the same vault, so the same URL should land the same way whichever one fetched
it: same frontmatter from the same signals, same elements dropped, same citation handling. Markdown flavour
may differ, since html2text and Turndown disagree about wrapping and emphasis. Equivalent, not identical.

`clip_wikipedia` was written to mirror the template and says so in a comment, but the two removal lists have
drifted apart, and one difference defeats the citation design outright:

| Selector | Template | ScrApe | Consequence |
| --- | --- | --- | --- |
| `.reference` | kept | stripped | markers deleted at clip time, so grooming has nothing to convert to `[^c]` |
| `.reflist` | — | stripped | reference list gone before grooming sees it |
| `.noprint` | kept | stripped | takes `[citation needed]` with it, which is signal |
| `.hatnote` | kept | stripped | that is content |
| `.shortdescription` | to `description` | kept | stranded in the body while the property stays empty |
| `style`, `link`, tracking pixel | stripped | kept | the CentralAutoLogin beacon survives |

Quick wins, all local to a list or a format string:

- Align that removal list. Keeping `.reference` matters most, as grooming depends on it.
- Take `description` from `.shortdescription` rather than leaving it empty.
- Bump the hardcoded template versions, 1.1 and 1.0, to the 1.2 both templates now carry.
- Add the `site` property to default clippings, and `todo` to their tags.
- Teach `sanitize_filename` the Obsidian characters `#`, `|`, `^`, `[`, `]`, which `safe_name` also strips.
- Decide whether `aliases`, built from first-paragraph bold text, should stay: it has no template equivalent.

Larger:

- Port Defuddle's metadata priority into `extract_meta`, which tries 4 author signals to its 11, 6 dates to 7
  and 2 descriptions to 6. The orders are recorded in the vault at `Repo-Plans/clipper-templates.md`.
- `clip_default` picks a body through a selector cascade, `article` then `.post-content` and so on, while the
  clipper runs Defuddle's readability scoring. These disagree about what *is* the article, not merely how it
  is written, so closing the gap means a readability library rather than more selectors.
- A parity check that clips one URL both ways and diffs the frontmatter, headings and links, so drift fails
  loudly instead of being discovered months later.

Prefer moving work into grooming wherever it can be expressed on markdown. Grooming is the same code on both
paths, so whatever it handles is equivalent by construction rather than by maintenance.
