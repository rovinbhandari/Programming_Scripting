// =============================================================
// Level 2 · Exercise 03 — Slices (&str and &[T])
// =============================================================
//
// CONCEPT
//   A *slice* is a borrowed VIEW into a contiguous run of elements — a "fat pointer"
//   carrying a start pointer AND a length. It owns nothing and copies nothing: it's a
//   window onto data someone else owns.
//     &[T]   a slice of an array / Vec   (e.g. `&a[1..4]`)
//     &str   a STRING slice              (a view into UTF-8 bytes)
//   Range syntax is half-open: `a..b` includes `a`, excludes `b`. A string literal
//   `"hello"` is itself a `&'static str` — a slice baked into the program binary.
//
//   GOTCHA you'll meet today: `&str` slicing is BYTE-indexed, and cutting through the
//   middle of a multi-byte UTF-8 character PANICS — at RUNTIME, not compile time.
//
// ANALOGIES
//   C# (tier 1):  `&[T]` ≈ `Span<T>` / `ReadOnlySpan<T>` — a length-carrying window over
//                 existing memory, no allocation, no copy. `&str` is the string flavour
//                 of that same idea (a view, not a freshly built string).
//   C / Python (tier 2):  C — a slice is `(ptr, len)` travelling TOGETHER, instead of a
//                 bare `char*` with the length kept out-of-band (and no null terminator).
//                 Python — `s[1:4]` looks identical BUT Python COPIES the slice; Rust's
//                 slice BORROWS — a view into the original, zero copy.
//   Plain concept: a borrowed window (pointer + length) onto part of a sequence.
//
// MEMORY MODEL
//      let s = String::from("hello world");
//      let w = &s[0..5];      // w borrows INTO s; it does not copy
//
//        s (String, owns) ──▶ HEAP:  h e l l o _ w o r l d
//                                     ▲         ▲
//        w = &s[0..5] ────────────────┘ ptr     │ len = 5     (window: "hello")
//
// TASK  (slice-flavoured fun in every rung)
//   1. SLICE OF LIFE  — make `let s = String::from("hello world");`, then carve
//      `&s[0..5]` and `&s[6..11]` and print both. In a comment, note that the slices
//      BORROW `s` (no new heap buffer is made).
//
//   2. ARRAY WINDOW  — `let a = [10, 20, 30, 40, 50];`  take `let mid = &a[1..4];` and
//      print it with `{:?}` plus its `.len()`. Same window idea, numbers edition.
//
//   3. FIRST WORD  — write `fn first_word(s: &str) -> &str` returning everything up to
//      the first space (or the whole string if there's none). Call it once with a
//      `&String` and once with a plain `"literal"` — BOTH work, because `&String`
//      auto-coerces to `&str`. (Returning a slice that borrows the input is the whole
//      trick; the lifetimes are inferred for you here.)
//
//   4. THE BYTE TRAP  — `let s = String::from("héllo");`  The `é` takes TWO bytes, so
//      `&s[0..2]` cuts a character in half. PREDICT first: compile error, or RUNTIME
//      panic? (Callback: ex07's `arr[const]` was a *compile* error — is this the same?)
//      Then run it and read the message. Finally FIX it by slicing at a real boundary
//      (`&s[0..1]` = "h", or `&s[0..3]` = "hé"). 🪤
//
//   5. SECRET INGREDIENT  — decode this `u8` run `as char` to name today's star:
//      [115, 108, 105, 99, 101]
//
// EXPECTED OUTPUT  (for the parts that compile cleanly — tasks 1–3 & 5)
//   hello
//   world
//   [20, 30, 40] len 3
//   <your first_word lines, e.g.>  hello  /  crab
//   slice
//
// HINTS
//   - `&v[a..b]` borrows the window `a..b`; `&v[..]` is the whole thing.
//   - `.char_indices()` yields `(byte_index, char)` pairs — handy for `first_word`.
//   - A multi-byte boundary panic is a RUNTIME event; that index is only known then.
//
// QUESTIONS TO PONDER  (answer in comments; mark yours with `// Q:`)
//   - Why must a slice carry a LENGTH, when a plain `&T` does not?
//   - Why is the byte-boundary failure a runtime PANIC, while ex07's `arr[10]` on a
//     fixed array was a COMPILE error? (Hint: when is each length known?)
//   - `"hello"` has type `&'static str` — who owns those bytes, and for how long?
//
// 🦀 Collectible — secret ingredient 3 of 4 = 'N'.   (so far: O · W · … — almost there.)
//
// Compile & run (Windows):  rustc 03_slices.rs && .\03_slices.exe
// Companion note:  03_slices_notes.md  (slices as borrowed (ptr,len) views; UTF-8 byte boundaries)
// -------------------------------------------------------------

fn main() {
    // ---- Task 1: SLICE OF LIFE (&str windows) ------------------------------
    // TODO: let s = String::from("hello world"); print &s[0..5] and &s[6..11].

    // ---- Task 2: ARRAY WINDOW (&[T]) ---------------------------------------
    // TODO: let a = [10,20,30,40,50]; let mid = &a[1..4]; print {:?} and .len().

    // ---- Task 3: FIRST WORD (a function returning a slice) -----------------
    // TODO: call first_word(&some_string) and first_word("a literal").

    // ---- Task 4: THE BYTE TRAP ---------------------------------------------
    // let s = String::from("héllo");
    // Q: compile error or runtime panic? -> ________
    // let bad = &s[0..2];           // uncomment to find out
    // println!("{bad}");
    // ...then fix it by slicing at a real char boundary.

    // ---- Task 5: SECRET INGREDIENT (decoder) -------------------------------
    let secret: [u8; 5] = [115, 108, 105, 99, 101];
    // TODO: print each byte `as char`, in order, to reveal the word.
    let _ = secret; // delete this line once you've used `secret`
}

// For Task 3 — implement this (uncomment it):
// fn first_word(s: &str) -> &str {
//     // walk the chars; return the slice up to the first space, else all of s.
//     todo!("return &s[..i] at the first space, or s")
// }
