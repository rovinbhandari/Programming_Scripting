// =============================================================
// Level 1 · Exercise 02 — Variables: let, mut, shadowing, const
// =============================================================
//
// CONCEPT
//   Bindings are **immutable by default**. Opt into mutation with `mut`.
//   "Shadowing" re-declares a name with a fresh `let` (and may change its type).
//   `const` is a compile-time constant that always needs a type annotation.
//
// ANALOGIES
//   C# (tier 1):  `var x = 1;` is mutable; Rust's plain `let x = 1;` behaves like
//                 a `readonly`. `const N` ~ C# `const`.
//   C / Python (tier 2):  C `const int`; Python has no real immutability for locals.
//   Plain concept: who is allowed to change this value, and when.
//
// TASK
//   1. `let x = 5;` then try `x = 6;` — compile it, READ the error, then comment the
//      reassignment out and write in a comment what the compiler told you.
//   2. Make a `let mut y = 5;` and reassign it to 6. Print before and after.
//   3. Shadowing: `let s = "42";` then `let s = s.len();` (now `s` is a number).
//      Print the final `s`. Note in a comment that the *type* changed.
//   4. Declare `const MAX_SCORE: u32 = 100;` and print it.
//
// HINTS
//   - Shadowing creates a NEW binding; `mut` reuses the SAME binding.
//   - `const` names are SCREAMING_SNAKE_CASE by convention.
//
// QUESTIONS TO PONDER
//   - What's the practical difference between re-`let` shadowing and `mut` reassignment?
//   - Why must a `const` have an explicit type, while a `let` often doesn't?
//
// 🦀 FERRIS'S FUN ZONE  (optional bonus — for delight, not grading)
//   Pun:        Don't be so `const`-ipated about change — when you truly need
//               it, just `mut` it up. (Shadowing? That's a value's glow-up.)
//   Side quest: Using ONLY shadowing (same name `x`, three `let`s, no `mut`),
//               start `let x = 5;`, grow to `x + 1`, then `x * 2`, and print 12.
//               Then recall the main task: shadowing changed a value's TYPE
//               (str -> its `.len()`). Could a single `mut` binding do that?
//               Note why or why not in a comment.
//   Collectible: Secret ingredient 2 of 7 = 'X'. Fitting — X marks the one
//               spot a binding is actually *allowed* to mutate.
//
// Compile & run (Windows):  rustc 02_variables.rs && .\02_variables.exe
// Companion note:  02_variables_notes.md  (let / mut / shadowing / const — binding vs place)
// -------------------------------------------------------------

fn main() {
    let x = 5;  // the compiler warns of unused variable (expected)
    // x = 6;   // can't work because "cannot assign twice to immutable variable"
    // Q: why is x a 'variable' when it's 'immutable' by default?

    let mut y = 5;
    println!("y={y}");
    y = 6;
    println!("y={y}");
    // y = "lkl"    // doesn't work because mut doesn't allow type-change apparently

    let s = "42";
    let s = s.len(); // s changed type from &str to usize
    println!("s={s}");

    const MAX_SCORE: u32 = 100; // type is mandatory here, probably because the compile stage will 
                                // replace the label with the value. (Q: does it?)
    println!("MAX_SCORE={MAX_SCORE}");
    // Q: what is the difference between const and immutable (default) variables? Both semantically and technically.

    // re-let vs mut:
    // From above it looks like mut can't allow type change whereas re-let does.
    // It seems that re-let will use a different memory location to allocate a variable
    // mut will probably reuse existing memory location since type change is prohibited. (Q: does it?)

    let x = 5;
    let x = x + 1;
    let x = x * 2;
    println!("x={x}");
}
