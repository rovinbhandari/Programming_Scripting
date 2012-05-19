
def genlist(n : Int) : List[Boolean] = 
{
	val r = new scala.util.Random;
	def rand() : Double = r.nextInt(200).asInstanceOf[Double] / 100.00
	def dist(p1 : Double, p2 : Double) : Double = 
	{
		//print("(" + p1 + ", " + p2 + ")");
		Math.sqrt(Math.pow(p1 - 1.00, 2) + Math.pow(p2 - 1.00, 2))
	}
	def list(d : Double, l : List[Boolean]) : List[Boolean] = 
	{
		//println("\t" + d);
		val len : Int = l.length;
		if(len % 10000 == 0) println((len / 10000) + "K")
		if(len > n) l else if(d < 1.00) list(dist(rand(), rand()), true :: l) else list(dist(rand(), rand()), false :: l)
	}
	list(dist(rand(), rand()), List())
}

def estimatedpi(l : List[Boolean]) : Double = 
{
	//println(l);
	def totaltrue(i : Int, count : Int) : Int = if(i < 0) count else if(l(i)) totaltrue(i - 1, count + 1) else totaltrue(i - 1, count)
	(totaltrue(l.length - 1, 0).asInstanceOf[Double] / l.length.asInstanceOf[Double]) * 4.00
}

val n : Int = Console.readInt();

println("Estimated value of pi (with " + n + " points) is : " + estimatedpi(genlist(n)));
