// =============================================================================
//  playground/borrowing.rs  —  "borrowing" vs "sharing" vs "moving"
//  Ahead-of-curriculum sandbox (NOT a numbered exercise — a keeper demo).
//  Run:  rustc borrowing.rs && ./borrowing      (Windows: .\borrowing.exe)
// =============================================================================
//
//  Q: Why "borrowing" and not "sharing"? If a friend borrows my car I don't have
//     it meanwhile — yet in Rust the original binding stays valid. What gives?
//
//  A: The analogy is fine; just map it to the RIGHT operation.
//
//   OWNERSHIP = who holds the *title* and must clean up (drop) the value.
//               Exactly ONE owner at a time.
//   MOVE      = hand the title over. The old binding becomes INVALID — *this* is
//               "I don't have it anymore" (give the car away / sell it).
//   BORROW    = lend temporary access WITHOUT giving up the title. The owner keeps
//               ownership and gets full use back when the borrow ends. Two flavours:
//                 &T     SHARED    (immutable): many at once, read-only.
//                                   Owner can still read.   <- the "sharing" feel.
//                 &mut T EXCLUSIVE (mutable):   exactly one, read-write.
//                                   Owner is LOCKED OUT until it ends.
//                                   <- here the car analogy fits perfectly.
//
//  So "share" only describes &T. &mut T is the *opposite* of shared. The single
//  umbrella word for "temporary, non-owning, must-give-back access" is BORROW.
//
//  THE ONE RULE  (aliasing XOR mutability):
//     at any instant you may have EITHER  one &mut T  XOR  any number of &T,
//     and no borrow may outlive its owner (no dangling).
//  That one rule is what makes data races impossible at *compile* time.
//
//  Tiers:
//   C# (1): &T ≈ `in` param (readonly ref); &mut T ≈ `ref` param. The rule is a
//           compile-time ReaderWriterLock — many readers XOR one writer. A *move*
//           has no real C# equivalent (references just alias; the GC cleans up).
//   C  (2): &T ≈ `const T*`; &mut T ≈ `T* restrict` (the no-alias promise you make
//           by hand in C — Rust proves it for you). Move ≈ pass ptr, NULL the old.
//   Py (2): every name is a shared, freely-mutable reference — exactly the
//           "mutate while iterating" footgun Rust turns into a compile error.
// =============================================================================

fn length(s: &String) -> usize {
    // borrows s (reads it) — does NOT take ownership, so the caller keeps it
    s.len()
}

fn main() {
    // 1) SHARED borrow (&T): read-only, MANY at once, owner can still read
    let x = 5;
    let r1 = &x;
    let r2 = &x; // a second shared borrow at the same time: perfectly fine
    println!("1) shared:    owner x={x}, readers r1={r1} r2={r2}  (all read at once)");

    // 2) EXCLUSIVE borrow (&mut T) inside a scope, then the owner gets it back
    let mut count = 10;
    {
        let m = &mut count; // while m is alive, `count` is lent out exclusively
        *m += 5; // mutate THROUGH the borrow
    } // <- borrow ends here; `count` is "returned" to its owner
    println!("2) exclusive: after the &mut ended, owner uses it again: count={count}");

    // 3) BORROW via a function (the everyday case): lend it, get it back
    let word = String::from("ownership");
    let n = length(&word); // lend &word — length() borrows, doesn't take
    println!("3) borrow fn: I still own '{word}' afterwards (len {n})");

    // 4) COPY vs MOVE — why the scalar exercises never tripped you up
    let a = 7; // i32 is `Copy`
    let b = a; // COPY: `a` is duplicated, not moved
    println!("4a) copy:     i32 is Copy, so a={a} AND b={b} are both valid");

    let owned = String::from("crab");
    let taken = owned; // MOVE: String is not `Copy`, so `owned` is emptied out
    // println!("{owned}"); // <- C4 below: this no longer compiles
    println!("4b) move:     String isn't Copy, so taken='{taken}' and `owned` is gone");
}

// =============================================================================
//  FUN ZONE — "Meet the Borrow Checker" 🦀   (predict the error, THEN uncomment)
//  Every snippet below is rejected at COMPILE time. Call the error yourself, then
//  uncomment to let rustc grade you. Hints only — answers are in the decoder key.
//
//  C1) shared borrow live, then mutate the owner:
//        let mut x = 5;  let r = &x;  x += 1;  println!("{r}");
//      hint: you can't scribble in a book three friends are reading.
//
//  C2) exclusive borrow live, then read the owner:
//        let mut c = 10; let m = &mut c; println!("{c}"); *m += 1;
//      hint: the writer booked the whole room — no peeking.
//
//  C3) two &mut at the same time:
//        let mut x = 5;  let a = &mut x;  let b = &mut x;  println!("{a}{b}");
//      hint: two cooks, one exclusive spoon.
//
//  C4) use a value after it was moved:
//        let owned = String::from("crab"); let taken = owned; println!("{owned}");
//      hint: you already gave the crab away.
//
//  C5) a borrow that outlives its owner (dangling):
//        let r; { let s = String::from("oops"); r = &s; } println!("{r}");
//      hint: the value left the building before the reference did.
//
//  Mantra: "shared XOR mutable — pick a lane." No &mut left behind. 🦀
//
//  ---- DECODER KEY (no peeking until you've guessed!) -------------------------
//  Cipher: ROT13 on letters + ROT5 on digits. It's self-inverse, so applying the
//  SAME transform decodes it (CyberChef "ROT13" with "rotate numbers" on, or a
//  tiny Rust loop — that's a bonus puzzle). Format: "Cn Ecode: message".
//    P6 R5051: pnaabg nffvta gb k orpnhfr vg vf obeebjrq
//    P7 R5057: pnaabg obeebj p nf vzzhgnoyr orpnhfr vg vf nyfb obeebjrq nf zhgnoyr
//    P8 R5944: pnaabg obeebj k nf zhgnoyr zber guna bapr ng n gvzr
//    P9 R5837: obeebj bs zbirq inyhr: bjarq
//    P0 R5042: f qbrf abg yvir ybat rabhtu
// =============================================================================
