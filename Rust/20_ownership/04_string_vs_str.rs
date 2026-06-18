// =============================================================
// Level 2 · Exercise 04 — String vs &str (own vs borrow)
// =============================================================
//
// CONCEPT
//   Rust splits "text" into two types, and the whole difference is OWNERSHIP:
//     String   owned, heap-allocated, GROWABLE & mutable. You own the buffer, you can
//              push onto it, and it's dropped when you're done.
//     &str     a borrowed, fixed VIEW of UTF-8 text. Owns nothing (it's a slice — ex03).
//   Rule of thumb:
//     • take `&str` as a function PARAMETER — most flexible: it accepts string literals
//       AND `&String` (which auto-coerces to `&str`).
//     • return or store a `String` when you need to OWN the text or GROW it.
//   Conversions:  &str -> String:  String::from(x) · x.to_string() · x.to_owned()
//                 String -> &str:  &s · s.as_str()   (deref coercion does it for free)
//
// ANALOGIES
//   C# (tier 1):  `String` ≈ owned, growable text (think `StringBuilder` for the
//                 mutation, an owned `string` for the value). `&str` ≈ `ReadOnlySpan
//                 <char>` — a borrowed view you don't own. C# hides this split behind one
//                 GC'd `string`; Rust makes you choose, because ownership is explicit.
//   C / Python (tier 2):  C — `String` ≈ a heap buffer you malloc/realloc/free yourself;
//                 `&str` ≈ a `(const char*, len)` window into someone else's bytes (but
//                 proven valid by the borrow checker). Python — one `str` type covers
//                 both; Rust separates "owned & growable" from "borrowed view".
//   Plain concept: own-and-grow (String) vs borrow-and-look (&str).
//
// MEMORY MODEL
//      let owned: String = String::from("crab");   // owns its heap bytes
//      let view:  &str   = &owned;                  // borrows INTO owned (no copy)
//      let lit:   &str   = "literal";               // borrows bytes baked in the binary
//
// TASK  (string puns mandatory; ownership is the through-line)
//   1. TWO KINDS  — make `let owned = String::from("Ferris");` and
//      `let slice: &str = "the crab";`  Print both, and in a comment label which one
//      OWNS its bytes and which merely BORROWS.
//
//   2. NO STRINGS ATTACHED  — write `fn greet(name: &str)` (it borrows — no strings
//      attached!). Call it TWICE: once with a literal `"world"`, once with a `&String`.
//      One signature, both callers, because `&String` coerces to `&str`. In a comment,
//      say why taking `&str` (not `String`) makes the function more reusable.
//
//   3. PULLING STRINGS  — build a `String` at runtime: `let mut s = String::from("foo");`
//      then `s.push_str("bar"); s.push('!');`  Then make another with `+` or `format!`
//      (e.g. `let louder = s + "?";`). Print it. In a comment, note what `s + "?"` does
//      to `s`'s ownership.  (Yes — it MOVES `s`.)
//
//   4. ROUND TRIP  — take a `&str`, turn it into a `String` (`.to_string()`), then turn
//      that back into a `&str` (`.as_str()` or `&s`). Print both ends and confirm the
//      text survived the trip intact.
//
//   5. SECRET INGREDIENT  — last one! decode this `u8` run `as char`:
//      [115, 116, 114, 105, 110, 103]
//
// EXPECTED OUTPUT  (roughly, for the compiling parts)
//   Ferris
//   the crab
//   Hi, world!        (however you phrase greet)
//   Hi, Crab!
//   foobar!?          (your built string)
//   <your round-trip prints>
//   string
//
// HINTS
//   - `"..."` is already a `&str`; `String::from("...")` or `.to_string()` makes it owned.
//   - `push_str` appends a `&str`; `push` appends a single `char`.
//   - `format!("{a}{b}")` builds a fresh `String` WITHOUT moving its inputs (unlike `+`).
//
// QUESTIONS TO PONDER  (answer in comments; mark yours with `// Q:`)
//   - Why does `fn greet(name: &str)` accept BOTH `"x"` and `&String`, while
//     `fn greet(name: String)` would force the caller to give up ownership?
//   - `let t = s + "?";` — why is `s` unusable afterwards, yet `format!` leaves its
//     inputs alone?
//   - When would you STORE a `&str` in a struct vs a `String`? (What does holding the
//     borrow tie you to?)
//
// 🦀 Collectible — secret ingredient 4 of 4 = 'S'.  You've gathered O · W · N · S —
//   what does an owner do with a value? It **OWNS** it. Level 2 word COMPLETE. 🦀🎉
//
// Compile & run (Windows):  rustc 04_string_vs_str.rs && .\04_string_vs_str.exe
// Companion note:  04_string_vs_str_notes.md  (own vs borrow; &str params; conversions)
// -------------------------------------------------------------

fn main() {
    // ---- Task 1: TWO KINDS -------------------------------------------------
    // TODO: let owned = String::from("Ferris"); let slice: &str = "the crab"; print both.

    // ---- Task 2: NO STRINGS ATTACHED (greet(&str)) -------------------------
    // TODO: call greet("world") and greet(&some_String).

    // ---- Task 3: PULLING STRINGS (build a String) --------------------------
    // TODO: let mut s = String::from("foo"); s.push_str("bar"); s.push('!');
    //       then combine with + or format!, and print.

    // ---- Task 4: ROUND TRIP (&str <-> String) ------------------------------
    // TODO: &str -> String via .to_string(); String -> &str via .as_str() or &s.

    // ---- Task 5: SECRET INGREDIENT (decoder) -------------------------------
    let secret: [u8; 6] = [115, 116, 114, 105, 110, 103];
    // TODO: print each byte `as char`, in order, to complete the level word.
    let _ = secret; // delete this line once you've used `secret`
}

// For Task 2 — implement this (uncomment it):
// fn greet(name: &str) {
//     // borrows `name` — accepts &str literals AND &String callers.
//     todo!("print a greeting using name")
// }
