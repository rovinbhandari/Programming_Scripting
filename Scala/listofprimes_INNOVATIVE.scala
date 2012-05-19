def isPrime(x : Int) : Boolean = 
{
	val u : Int = Math.floor(Math.sqrt(x)).asInstanceOf[Int];
	def nooffactors(i : Int, count : Int) : Int = if(i >= u && x % i == 0) 1 else if(i >= u && x % i != 0) count else if(x % i == 0) 1 else nooffactors(i + 1, count)
	if(x == 0 || x == 1) false else if(x == 2) true else (nooffactors(2, 0) == 0)
}

def primesInRange(x : (Int, Int)) : List[Int] = List.range(x._1, x._2) filter isPrime

val input = Tuple2(Console.readInt(), Console.readInt());
println("\n primesInRange(" + input + ") = " + primesInRange(input));
