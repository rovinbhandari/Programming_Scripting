// =============================================================
// Level 2 · Exercise 02 — References & Borrowing (&T, &mut T)
// =============================================================
//
// CONCEPT
//   A *reference* lets you use a value WITHOUT owning it — you "borrow" it and give
//   it back. No move happens, so the owner keeps the value. Two flavours:
//     &T      SHARED    (immutable): many at once, read-only. Owner can still read.
//     &mut T  EXCLUSIVE (mutable):   exactly ONE, read-write. Nobody else may touch
//             the value — not even the owner — until that borrow ends.
//   THE ONE RULE  (aliasing XOR mutability):
//     at any instant you may have EITHER one &mut T  XOR  any number of &T —
//     never both — and no borrow may outlive its owner (no dangling).
//   That single rule is how Rust makes data races a COMPILE error, for free.
//   (You met a sneak preview in `playground/borrowing.rs`; this is the real rung.)
//
//   NLL (non-lexical lifetimes): a borrow ends at its LAST USE, not at the closing
//   brace. A reference you never touch again quietly releases the value early.
//
// ANALOGIES
//   C# (tier 1):  &T ≈ an `in` parameter (readonly ref); &mut T ≈ a `ref` parameter.
//                 THE ONE RULE is a compile-time ReaderWriterLock — many readers XOR
//                 one writer — but proven by the compiler, with ZERO runtime cost.
//   C / Python (tier 2):  C — &T ≈ `const T*`; &mut T ≈ `T* restrict` (the "no other
//                 alias" promise you make by hand in C — Rust PROVES it). Python — names
//                 freely alias one mutable object (the "mutate while iterating" footgun);
//                 Rust turns that exact footgun into a compile error.
//   Plain concept: temporary, non-owning access — shared-and-readonly, OR
//                 exclusive-and-writable, but never both at the same time.
//
// TASK  (fun baked into each rung — and you predict before you compile)
//   1. LIBRARY CARD  — `let x = 5;` then make TWO shared borrows `let r1 = &x;` and
//      `let r2 = &x;`, and print `x`, `r1`, `r2` together. Many readers, no problem.
//
//   2. ONE LOUD EDITOR  — `let mut count = 10;`  Inside a `{ }` block, take
//      `let m = &mut count;`, do `*m += 5;` (mutate THROUGH the borrow), then close
//      the block. AFTER it, print `count`. The owner got it back — say WHY the inner
//      block matters, in a comment.
//
//   3. BORROW, DON'T TAKE  — write `fn char_count(s: &String) -> usize` that returns
//      `s.len()` by BORROWING, then keep using your String afterwards. No move this
//      time (contrast ex01's `take`, which devoured the String).
//
//   4. RULE-BREAKER ARCADE  — five one-liners the borrow checker REJECTS. For EACH,
//      write your predicted error code (E0___) in a comment, THEN uncomment it (one at
//      a time) and let rustc grade you. The hint rhymes with the crime:
//        a) shared borrow live, then scribble on the owner:
//             let mut x = 5; let r = &x; x += 1; println!("{r}");
//           "can't edit a book three friends are mid-sentence in."
//        b) exclusive borrow live, then peek at the owner:
//             let mut c = 10; let m = &mut c; println!("{c}"); *m += 1;
//           "the editor booked the whole room — no peeking."
//        c) two exclusive borrows at once:
//             let mut x = 5; let a = &mut x; let b = &mut x; println!("{a}{b}");
//           "two cooks, one exclusive spoon."
//        d) shared AND exclusive at the same time:
//             let mut x = 5; let r = &x; let m = &mut x; println!("{r}{m}");
//           "readers in the room AND a writer? pick a lane."
//        e) a borrow that outlives its value (dangling):
//             let r; { let s = String::from("oops"); r = &s; } println!("{r}");
//           "the value left the building before the reference did."
//      Bonus (NLL): rule-breaker (a) turns LEGAL with a mere REORDER — read `r`
//      BEFORE `x += 1` instead of after. Try it; a borrow ends at its LAST use. 🦀
//
//   5. SECRET INGREDIENT  — decode this `u8` run `as char` to spell the umbrella word
//      for "temporary, non-owning access":   [98, 111, 114, 114, 111, 119]
//
// EXPECTED OUTPUT  (for the parts that COMPILE — tasks 1–3 & 5)
//   5 5 5
//   15
//   <your char_count line, e.g.>  crab has 4 bytes
//   borrow
//
// HINTS
//   - `&x` makes a shared ref; `&mut x` an exclusive one; read/write through `&mut`
//     with the `*` deref (e.g. `*m += 5`).
//   - rustc points at where each borrow STARTS and where it is still IN USE.
//   - Task 4 only compiles when every rule-breaker is commented out again.
//
// QUESTIONS TO PONDER  (answer in comments; mark yours with `// Q:`)
//   - Why is "many readers XOR one writer" enough to make data races impossible?
//   - In 4a, why does reading `r` *before* `x += 1` compile, while reading it *after*
//     does not?
//   - Is "&mut means the owner temporarily loses access" a fair mental model?
//
// 🦀 Collectible — secret ingredient 2 of 4 = 'W'.   (1 of 4 was 'O' — keep collecting.)
//
// Compile & run (Windows):  rustc 02_references_borrow.rs && .\02_references_borrow.exe
// Companion note:  02_references_borrow_notes.md  (the one rule: aliasing XOR mutability; NLL)
// -------------------------------------------------------------

fn main() {
    // ---- Task 1: LIBRARY CARD (shared borrows) -----------------------------
    // TODO: let x = 5; make r1 = &x and r2 = &x; print x, r1, r2 together.

    // ---- Task 2: ONE LOUD EDITOR (&mut inside a scope) ---------------------
    // TODO: let mut count = 10; { let m = &mut count; *m += 5; } then print count.

    // ---- Task 3: BORROW, DON'T TAKE (a borrowing fn) -----------------------
    // TODO: call char_count(&your_string), then keep using your_string.

    // ---- Task 4: RULE-BREAKER ARCADE ---------------------------------------
    // Predict each error code in a comment, THEN uncomment ONE line at a time:
    // a) let mut x = 5; let r = &x; x += 1; println!("{r}");                 // E0___ ?
    // b) let mut c = 10; let m = &mut c; println!("{c}"); *m += 1;           // E0___ ?
    // c) let mut x = 5; let a = &mut x; let b = &mut x; println!("{a}{b}");  // E0___ ?
    // d) let mut x = 5; let r = &x; let m = &mut x; println!("{r}{m}");      // E0___ ?
    // e) let r; { let s = String::from("oops"); r = &s; } println!("{r}");   // E0___ ?

    // ---- Task 5: SECRET INGREDIENT (decoder) -------------------------------
    let secret: [u8; 6] = [98, 111, 114, 114, 111, 119];
    // TODO: print each byte `as char`, in order, to reveal the word.
    let _ = secret; // delete this line once you've used `secret`
}

// For Task 3 — implement this borrowing function (uncomment it):
// fn char_count(s: &String) -> usize {
//     // borrow s (read-only) and return its byte length — does NOT take ownership.
//     todo!("return s.len()")
// }
