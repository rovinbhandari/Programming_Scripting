// =============================================================
// Level 2 · Exercise 01 — Ownership & the Move
// =============================================================
//
// CONCEPT
//   Ownership is Rust's headline act — the idea with no real C#/Python twin.
//   Three rules to get into your bones:
//     1. Every *owned* value (like a `String`) has exactly ONE owner at a time.
//        (Shared-ownership types `Rc`/`Arc` exist for much later — ignore them now.)
//     2. When the owner goes out of scope, the value is dropped — freed
//        deterministically, with NO garbage collector.
//     3. Assigning or passing a NON-`Copy` value MOVES it: the old binding is
//        retired, and using it again is a *compile* error (not a runtime crash).
//   `Copy` types — the Level-1 scalars (i32, bool, char, …) — sidestep all this by
//   DUPLICATING on assignment, so both names stay valid. That's why ex01–07 never
//   tripped you on this.
//
// ANALOGIES
//   C# (tier 1):  assigning a class instance just ALIASES it (two refs, one heap
//                 object, the GC frees it later) — C# never invalidates the source.
//                 A C# `struct` copies on assignment; Rust `Copy` is like that but
//                 STRICTER (every field must be Copy and the type has no destructor).
//                 A Rust *move* is a struct-style copy that ALSO retires the original.
//   C / Python (tier 2):  C — picture copying the {ptr, len, cap} bookkeeping and then
//                 treating the old variable as unusable; Rust proves that at compile
//                 time, so no double-free. Python — `b = a` binds a second name to the
//                 SAME object; Rust instead hands ownership to `b` and retires `a`.
//   Plain concept: who is responsible for freeing a value, and what happens to the old
//                 name when you hand that responsibility to a new one.
//
// MEMORY MODEL  (picture it before you code)
//      let s = String::from("crab");
//
//        STACK                    HEAP
//      s ┌──────────┐           ┌───────────────┐
//        │ ptr   ───┼──────────▶│ c  r  a  b    │  (UTF-8 bytes)
//        │ len    4 │           └───────────────┘
//        │ cap    4 │
//        └──────────┘
//   Conceptually a `String` is a `Vec<u8>`: it parks THREE words on the STACK (a
//   pointer, a length, a capacity) while the actual UTF-8 bytes live on the HEAP.
//   Moving a String hands over those three words plus ownership of the heap buffer —
//   the bytes are NOT re-copied (cheap). `.clone()` is what duplicates the heap bytes.
//
// TASK  (every rung has a little fun baked in — that's the point now)
//   1. COPY CATS  — "Copy that, Ferris!"  Make `let a = 7;` then `let b = a;` and
//      print BOTH on one line. They coexist because `i32` is `Copy`. In a comment,
//      say what `let b = a;` did to `a`  (spoiler: nothing — `a` was duplicated).
//
//   2. MOVING DAY  — `let s1 = String::from("crab"); let s2 = s1;`  Now ALSO try to
//      `println!("{s1}")`.  Before you compile, PREDICT the error code in a comment
//      (it's an `E0__2`-shaped code — guess the middle digits!). Then compile and let
//      rustc grade you. In a comment, say who owns "crab" after the move.
//
//   3. CLONE WARS  — make task 2 print BOTH `s1` and `s2` by giving each its own heap
//      buffer (hint: one method call). In a comment, say which is cheaper — a move or
//      a clone — and WHY (think: how many heap bytes get copied each time).
//
//   4. GIVE & TAKE  — write `fn take(s: String)` that prints `s` (it now OWNS the
//      string and drops it at the end). Call it, then try to use your string
//      afterwards — feel the move bite. Then write `fn take_give(s: String) -> String`
//      that prints AND returns the string so you can keep using the returned binding.
//      (Tedious, right? Exercise 02 fixes this with *borrowing* — there's a sneak peek
//      already living in `playground/borrowing.rs`.)
//
//   5. HEAP DETECTIVE  — in a comment, name the THREE things a `String` parks on the
//      stack and the ONE thing it leaves on the heap. Then DECODE: the array below is
//      a run of `u8` bytes — cast each one `as char` and print them IN ORDER to reveal
//      where a String's characters actually live.
//      Bonus (a Level-1 callback): why `u8 as char` and not `i32 as char`? Try typing
//      the array as `[i32; 4]` instead and read the error rustc throws. 🦀
//
// EXPECTED OUTPUT  (roughly, once tasks 1–5 work)
//   7 7
//   crab crab            // after the clone, both s1 and s2 still print
//   ...(your take / take_give lines)...
//   heap
//
// HINTS
//   - Make an owned String with `String::from("...")` or `"...".to_string()`.
//   - A moved-from variable is NOT "null" or "empty" — it's simply OFF-LIMITS.
//   - `as char` is only valid FROM a `u8`; that's why the decoder array is `[u8; N]`.
//
// QUESTIONS TO PONDER  (answer in comments; mark yours with `// Q:`)
//   - Why doesn't Rust just shallow-copy and keep BOTH names valid? (What disaster
//     happens when two owners of one heap buffer both go out of scope?)
//   - After `let s2 = s1;`, what exactly got written onto the stack — and what did NOT?
//   - Can a type *opt in* to `Copy`? Under what conditions is that even allowed?
//
// 🦀 Collectible — secret ingredient 1 of 4 = 'O'.
//   This level's word is what an owner *does* to its value (4 letters). Gather one
//   letter per file across `20_ownership/` to spell it.
//
// Compile & run (Windows):  rustc 01_ownership_move.rs && .\01_ownership_move.exe
// Companion note:  01_ownership_move_notes.md  (move vs Copy; stack/heap; no double-free)
// -------------------------------------------------------------

fn main() {
    // ---- Task 1: COPY CATS -------------------------------------------------
    // TODO: let a = 7; let b = a; then print both a and b on one line.

    // ---- Task 2: MOVING DAY ------------------------------------------------
    // TODO: let s1 = String::from("crab"); let s2 = s1;
    //       // Q: I predict the error is E0____
    //       then ALSO try to print s1, compile, and read rustc's verdict.

    // ---- Task 3: CLONE WARS ------------------------------------------------
    // TODO: make BOTH s1 and s2 printable by giving each its own heap buffer.

    // ---- Task 4: GIVE & TAKE ----------------------------------------------
    // TODO: call take(...) with a String, feel the move; then use take_give(...)
    //       to get ownership back and keep using the returned binding.

    // ---- Task 5: HEAP DETECTIVE -------------------------------------------
    // In a comment: which THREE things sit on the stack? which ONE on the heap?
    let clue: [u8; 4] = [104, 101, 97, 112];
    // TODO: cast each byte `as char` and print them in order to reveal the answer.
    let _ = clue; // delete this line once you've used `clue`
}

// Uncomment and implement these two for Task 4:
// fn take(s: String) {
//     // `s` is OWNED here; it will be dropped when this function returns.
//     todo!("print s")
// }
// fn take_give(s: String) -> String {
//     // print s, then hand ownership back to the caller.
//     todo!("print s, then return it")
// }
