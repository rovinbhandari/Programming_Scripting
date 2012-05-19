// such numbers are called 'facorions'

val factorials : List[Int] = List(1, 1, 2, 6, 24, 120, 720, 5040, 40320, 362880)

def fac(x : Int) : Int = factorials(x)

def sofod(x : Int) : Int = if(x == 0) 0 else (fac(x % 10) + sofod(x / 10))

def numgen(n : Int) : Int = //List[Int] =
{
	//var l : List[Int] = List();
	
	var sum : Int = 0;
	
	for
	{
		i <- 10 to n
		if i == sofod(i)
	}
		//println("\n" + i)
		//i :: l
		sum += i
	//l
	sum
}

println("\n\t" + numgen(9999999));	// because 7.9! < 10^7 - 1 
					// TODO: look for a tighter bound (e.g. 50000)
