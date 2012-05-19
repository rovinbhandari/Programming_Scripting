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
		bar("YEAH")
	}
	
	def bar(t : java.lang.String) : Unit = 
	{
		Console.println(t + "!!!")
	}
	
}
