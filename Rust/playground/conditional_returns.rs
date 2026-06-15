// =============================================================================
//  playground/conditional_returns.rs  —  value-returning `if` / `match` (no `;`)
//  Ahead-of-curriculum sandbox (previews 04_functions & 05_control_flow).
//  Run:  rustc conditional_returns.rs && .\conditional_returns.exe
// =============================================================================
//
//  Q: Can a function have "two conditional value returns" without a `;`?
//
//  A: Yes — but the framing is the trick. It's NOT two returns. It's ONE tail
//     expression (an `if/else` or a `match`) whose *branches* each sit in tail
//     position. In Rust a block's value is its final expression-with-no-`;`, and
//     `if`/`match` are EXPRESSIONS — so each branch's tail becomes the value the
//     whole expression evaluates to, which becomes the function's return value.
//
//   fn sign(x: i32) -> i32 {
//       if x >= 0 { 1 } else { -1 }   // <- ONE expression, two arms, no `;`
//   }
//
//   Three rules fall out of that:
//     1) Every branch must unify to the SAME type (the return type). Mismatch =
//        compile error, not a runtime surprise.
//     2) An `if` used as a value NEEDS an `else` (a lone `if {..}` is type `()`).
//     3) `return x;` is the *other* mechanism: an explicit early return. That one
//        IS a statement — it takes a `;` and can appear anywhere, not just the end.
//
//  "Two or more" generalises to `match` (N arms) — same no-`;` tail rule.
//
//  Tiers:
//   C# (1): BIG difference — in C# `if` is a STATEMENT, so `int s = if(..)..;` is
//           illegal. You'd reach for the ternary `cond ? a : b`, a `switch`
//           expression `x switch { ... }` (C# 8+), or an explicit `return`.
//           Map: Rust `if/else`-value ≈ C# `?:`; Rust `match` ≈ C# `switch` expr.
//   C  (2): same as C# — `if` is a statement; the expression form is `cond ? a : b`.
//   Py (2): `if` is a statement; the expression form is `a if cond else b`
//           (Python's `match`, 3.10+, is a statement too — not a value).
//   Concept: Rust is "expression-oriented" — almost everything yields a value,
//            so control flow can BE the value instead of merely choosing one.
// =============================================================================

// 1) The direct answer: two arms, both bare (no `;`), one tail `if/else`.
fn sign(x: i32) -> i32 {
    if x >= 0 {
        1
    } else {
        -1
    }
}

// 2) "Two" generalises to "many": a `match` is one tail expression with N arms.
fn signum_word(x: i32) -> &'static str {
    match x {
        0 => "zero",
        n if n > 0 => "positive",
        _ => "negative",
    }
}

// 3) else-if chains are still ONE expression (each block's tail is bare).
fn grade(score: u32) -> char {
    if score >= 90 {
        'A'
    } else if score >= 80 {
        'B'
    } else if score >= 70 {
        'C'
    } else {
        'F'
    }
}

// 4) Mixing both styles: early `return` (a statement, needs `;`) guards the edge,
//    then a tail `if/else` (no `;`) produces the normal value.
fn classify(x: i32) -> &'static str {
    if x < 0 {
        return "neg"; // early exit — `return` + `;`
    }
    if x == 0 {
        "zero"
    } else {
        "pos"
    } // <- tail expression: the function's value when x >= 0
}

fn main() {
    println!("1) if/else tail : sign(5)={}  sign(-5)={}", sign(5), sign(-5));
    println!(
        "2) match (N arms): {} / {} / {}",
        signum_word(0),
        signum_word(7),
        signum_word(-7)
    );
    println!("3) else-if chain : grade(95)={}  grade(83)={}  grade(40)={}", grade(95), grade(83), grade(40));
    println!(
        "4) return + tail : classify(-1)={}  classify(0)={}  classify(3)={}",
        classify(-1),
        classify(0),
        classify(3)
    );
}

// =============================================================================
//  🦀 WHAT-BREAKS ZONE  (predict the compiler's verdict, THEN uncomment)
//  Both snippets are rejected at COMPILE time — they teach rules 1 & 2 above.
//  Hints only; the exact error codes/messages are in the notes' answer key.
//
//  W1) arms disagree on type:
//        fn f(b: bool) -> i32 { if b { 1 } else { "no" } }
//      hint: both forks of the road must be paved with the same material.
//
//  W2) `if` used as a value with no `else`:
//        fn g(b: bool) -> i32 { if b { 1 } }
//      hint: what value does the "didn't happen" path hand back?
//
//  Mantra: "every arm, one type — or no value at all." 🦀
//  (We'll make this muscle-memory in 04_functions & 05_control_flow.)
// =============================================================================
