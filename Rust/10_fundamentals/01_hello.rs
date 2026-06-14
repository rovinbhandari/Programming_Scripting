// =============================================================
// Level 1 · Exercise 01 — Printing & format args
// =============================================================
//
// CONCEPT
//   Output text with the `println!` / `print!` macros and Rust's `{}` format
//   placeholders (named, positional, and the `{:?}` "debug" form).
//
// ANALOGIES
//   C# (tier 1):  Console.WriteLine($"Hello {name}");  Console.Write("no newline");
//   C / Python (tier 2):  C `printf("%d\n", x);`  ·  Python `print(f"{x}")`.
//   Plain concept: send formatted text to standard output.
//
// TASK
//   1. Print exactly:  Hello, Rust!
//   2. Make a `let name = "Ferris";` and print:  Hello, Ferris!  using a placeholder.
//   3. Make two integers and print one line:  3 + 4 = 7   (compute the sum, don't hardcode).
//   4. (stretch) Print a value using debug formatting `{:?}` and notice how it differs.
//
// EXPECTED OUTPUT (roughly)
//   Hello, Rust!
//   Hello, Ferris!
//   3 + 4 = 7
//
// HINTS
//   - Placeholders can be positional `{}` or capture a variable by name `{name}`.
//   - `print!` has no trailing newline; `println!` adds one.
//
// QUESTIONS TO PONDER  (answer in comments; mark yours with `// Q:`)
//   - Why does `println!` end in `!` — what makes it a *macro* and not a function?
//   - What's the difference between `{}` (Display) and `{:?}` (Debug)?
//
// 🦀 FERRIS'S FUN ZONE  (optional bonus — for delight, not grading)
//   Pun:        Crabs don't say "Hello" — they say "Shello, World!"
//               So let's `print!` something and shell-ebrate. 🦀
//   Side quest: Print all three required lines using a SINGLE `println!`
//               (hint: `\n` is one newline inside the string). Then, from the
//               pair ("Hello", "Ferris"), print  Ferris, Hello!  using ONLY
//               positional args `{1}` and `{0}` — same data, brand-new order.
//   Easter egg: Try printing this tiny crab:   (\/)!_!(\/)
//               Gotcha: to put a literal backslash in a string you write `\\`.
//   Collectible: Secret ingredient 1 of 7 = 'O'. Every exercise in this level
//               hands you one letter; collect all seven to spell what iron
//               quietly does in damp air (and why this language is so named).
//
// Compile & run (Windows):  rustc 01_hello.rs && .\01_hello.exe
// Companion note:  01_hello_notes.md  (why println! is a macro — compile-time formatting)
// -------------------------------------------------------------

#[derive(Debug)]
struct Point 
{
    x : i32,
    y : i32,
}

fn main() {
    println!("Hello, Rust!");   // println! might be a macro instead of a function because it seems that
                                // in Rust, functions can't take unspecified number of parameters (like param[] or ... )
                                // and that macros can be frontloaded to pre-compile stage (Rust philosophy?)
    
    let name = "Ferris";
    let greeting = "Hello";
    println!("{greeting}, {name}!");
    println!("{1}, {0}!", greeting, name);
    
    let num1 = 3;
    let num2: i64 = 4;
    let sum = num1 + num2;
    println!("{num1} + {num2} = {sum}");

    println!("{:?}", greeting); // Debug println might show us more info than just Display println
                                // especially for custom objects where Display might not be overridden (Q: is it?)
    let point = Point { x : 5, y : 3 };
    // println!("{point}"); // can't work yet because Display is not implemented.
    println!("{point:?}"); // Q: why does this give a warning for dead code?

    print!("What musical instrument does a crab play?\n...\nA shello!\n");

    let claw = "(\\/)";
    println!("{claw}!_!{claw}");

    // Q: Does Rust support adding arbitrary comma separated values in println!() ?
}
