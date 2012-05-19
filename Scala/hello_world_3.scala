// hello world in scala


object hello
{

	def foo(s : java.lang.String) : Unit = 
	{
		Console.println(s)
	}
	
	def main(args : Array[String]) : Unit =
	{
		Console.println("Scalafirst")	
		foo("working!!")
		bar("pi = ", 3.14)
		bar("zero = ")
	}
	
	def bar(t : java.lang.String, d : Double = 0.0) : Unit = 
	{
		Console.println(t + Double.toString(d))
	}
	
}
