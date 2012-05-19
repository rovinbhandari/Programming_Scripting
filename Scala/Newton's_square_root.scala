/*
	to find the square root of a number 'n' using Newton's method (involving an initial guess 'g') as :
		g = (g + n/g)/2 until g*g ~ n
*/


object sqrt
{
	def guess_iteration(guess : Double, num : Double) : Double = 
	{
		if(GGguess(guess, num))
			guess
		else
			guess_iteration(GGifyguess(guess, num), num)
	}
	
	def GGguess(guess : Double, num : Double) : Boolean =
	{
		Math.abs(guess * guess - num) < 0.001
	}
	
	def GGifyguess(guess : Double, num : Double) : Double = 
	{
		(guess + num / guess) / 2
	}
	
	def Newton_sqrt : Unit = 
	{	
		var num = Console.readDouble();
		Console.println(guess_iteration(1.0, num))
	}
	
	def main(args : Array[String]) : Unit =
	{
		Newton_sqrt
	}
}
