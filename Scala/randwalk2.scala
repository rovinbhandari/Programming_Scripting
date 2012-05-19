val platx:Int = 20;
val platy:Int = 20;
//val dim:Int = (platx + 1) * (platy + 1)

//var path = new Array[Array[Boolean]](platx + 1, platy + 1)

val r = new scala.util.Random

def rand(x:Int):Int = r.nextInt(x)

def userinp():List[(Int,Int)] = List(Tuple2(Console.readInt(), Console.readInt()), Tuple2(Console.readInt(), Console.readInt()))

def move(l : List[(Int, Int)]) : List[(Int, Int)] = 
{
	println(l(0));
	//path(l(0)._1)(l(0)._2) = true;
	if(l(0) == l(1)) l
	else move(List(nextstep(l),l(1)))
}

def nextstep(l:List[(Int,Int)]):(Int,Int) = 
{
	val x: Int= l(0)._1;
	val y: Int= l(0)._2;
	val dx: Int= l(1)._1;
	val dy: Int= l(1)._2;
	val ranges = probrange(Tuple4(x, y, dx, dy));		// temporarily a tupple is being passed. to be replaced by l.
	var step:Int = rand(ranges._1+ranges._2+ranges._3+ranges._4);
	if(step<ranges._1) Tuple2(x,y+1)
	else if(step<ranges._1+ranges._2) Tuple2(x,y-1)
	else if(step<ranges._1+ranges._2+ranges._3) Tuple2(x+1,y)
	else Tuple2(x-1,y)
}

def probrange(pt:(Int,Int,Int,Int)):(Int,Int,Int,Int) = 
{
	val pN : Int = if(pt._2 < platy) Math.pow(Math.abs(pt._4-pt._2+1), 2 * 2).asInstanceOf[Int] else 0;
	val pS : Int = if(pt._2 > 0) Math.pow(Math.abs(pt._4-pt._2-1), 2 * 2).asInstanceOf[Int] else 0;
	val pE : Int = if(pt._1 < platx) Math.pow(Math.abs(pt._3-pt._1+1), 2 * 2).asInstanceOf[Int] else 0;
	val pW : Int = if(pt._1 > 0) Math.pow(Math.abs(pt._3-pt._1-1), 2 * 2).asInstanceOf[Int] else 0;
	Tuple4(pN,pS,pE,pW)
}

val temp:List[(Int,Int)] = move(userinp());

/*
for(i <- 0 to platx)
{
	for(j <- 0 to platy)
	{
		if(path(i)(j))
			print('*');
		else
			print(' ');
	}
	println();
}
*/
/*
{
	i <- 0 to platx
}
	for
	{
		j <- 0 to platy
		if path(i)(j)
	}
		print('*');
	println();
*/
