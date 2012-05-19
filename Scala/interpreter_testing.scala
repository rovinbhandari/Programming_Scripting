def foo(x : Int) : Int = x * x + 5

def bar(f : Int => Int, x : Int) : Double = Math.sqrt(f(x))

def baz(x : Int, y : Int) : String = "" + x + "" + y + "" + x + y + "\n"

println("" + foo(4) + " haha \n")
