import java.lang._;
object randwalk{
	var passengers:passinfo = new passinfo();
	var passlist:List[passenger] = List();
	//var list :List[passenger]
	var plat:platform = new platform(10,10);
	def main(args:Array[String]):Unit = {
		plat.prepgrid();
		for(i <- 0 to (plat.platx-1)){for(j <- 0 to (plat.platy-1)) print(plat.platgrid(i)(j)); println();}
		enter_train(1);
		printsrcpos();
		for(pass<-passengers.list) passlist = pass::passlist;
		movepass();
		//println("\nIndividual Paths :\n--------------------");
		//for(pass<-passengers.list.reverse){println(pass.pid); 
			//for(pos<-pass.path.reverse) println(pos);}
	}
	def enter_train(x:Int) = {  // put list of passengers on train to passenger list
		passengers.list = new passenger((0,2),(9,5),passengers.list.length,plat)::passengers.list;
		passengers.list = new passenger((2,0),(6,9),passengers.list.length,plat)::passengers.list;
		passengers.list = new passenger((0,9),(9,0),passengers.list.length,plat)::passengers.list;
		passengers.list = new passenger((3,0),(8,9),passengers.list.length,plat)::passengers.list;
		passengers.list = new passenger((3,0),(9,6),passengers.list.length,plat)::passengers.list;
		passengers.list = new passenger((1,9),(1,0),passengers.list.length,plat)::passengers.list;
		passengers.list = new passenger((6,0),(1,9),passengers.list.length,plat)::passengers.list;
		passengers.list = new passenger((0,0),(9,3),passengers.list.length,plat)::passengers.list;
		passengers.list = new passenger((9,9),(0,5),passengers.list.length,plat)::passengers.list;
		passengers.list = new passenger((0,8),(9,8),passengers.list.length,plat)::passengers.list;
	}
	
	def printsrcpos():Unit = 
	{
		println("Live Movement :\n------------------");
		for(pass <- passengers.list.reverse){
			println(pass.pid + "\t" + pass.pos);
			plat.platgrid(pass.pos._1)(pass.pos._2) = pass.pid;
		}
		println();
	}
	
	def movepass():Unit = {
		System.out.print("\u001b[2J");
		System.out.flush();
		for(i <- 0 to (plat.platx-1)) {print("\t\t\t\t"); for(j <- 0 to (plat.platy-1)) if(plat.platgrid(i)(j)== -1) print("* ") /*else if(plat.platgrid(j)(i)== 0) print("#")*/ else print(plat.platgrid(i)(j) + " "); println();}
		println("\n\n\n\n\n");
		Thread.sleep(1200);
		
		//println(passlist.length);
		if(passlist.length!=0){
			passlist = passlist.remove(pass=>(pass.pos==pass.dest));
			//println(passlist.length+"\n");
			for(pass<-passlist){
				plat.platgrid(pass.pos._1)(pass.pos._2) = -1;
				pass.move();
				pass.path = pass.pos::pass.path;
				plat.platgrid(pass.pos._1)(pass.pos._2) = pass.pid;
				println(pass.pid + "\t" + pass.pos);
				
				var count : Int = 0;
				for{p <- passlist if p.pos == pass.pos} count += 1;
				if(count > 1) println("\n\t\tCOLLISION HOGYI\n");
			}
			movepass();
		}
	}
}

class platform(x:Int,y:Int){
	val platx:Int = x;
	val platy:Int = y;
	var platgrid = new Array[Array[Int]](x,y);
	var ci = new Array[Array[Int]](x,y);
	def prepgrid():Unit = for(i <- 0 to (platx - 1)){ for(j <- 0 to (platy-1)) platgrid(i)(j) = -1;}
	def calci(x:Int,y:Int):Int = {
		var comfinit:Int = 0;
		var comfpenalty:Int = -1;
		var comf:Int = comfinit;
		for(i <- (x-1) to (x+1)){for(j <- (y-1) to (y+1)){
				if(i>=0 && j>=0 && i!=j) comfinit-= {if(platgrid(i)(j)!= -1) 1 else comfpenalty};}}
		comfinit
	}
}

class passenger(src:(Int,Int),des:(Int,Int),id:Int,pla:platform){
	val plat:platform = pla;
	val pid:Int = id;
	val source:(Int,Int) = src;
	val dest:(Int,Int) = des;
	var pos:(Int,Int) = src;
	var path:List[(Int,Int)] = List(src);
	
	def move():Unit = {
		val r = new scala.util.Random
		def rand(x:Int):Int = r.nextInt(x)
		
		//var ranges = probrange(Tuple4(pos._1,pos._2,dest._1,dest._2));		
		
		var ranges = probrange(Tuple4(pos._1,pos._2,dest._1,dest._2));
		ranges = collision_aversion_ranges(ranges);
				
		val n:Int = ranges._1+ranges._2+ranges._3+ranges._4;
		//println("\t\t\tN = " + n); //System.exit(0);
		var step:Int = 0;
		if(n > 0)
			step = rand(n);
		if(n == 0) pos = Tuple2(pos._1,pos._2);
		else if(step<ranges._1) pos=Tuple2(pos._1 -1 ,pos._2);
		else if(step<ranges._1+ranges._2) pos=Tuple2(pos._1 + 1,pos._2);
		else if(step<ranges._1+ranges._2+ranges._3) pos=Tuple2(pos._1,pos._2 + 1);
		else pos=Tuple2(pos._1,pos._2 - 1);
	}
	
	def probrange(pt:(Int,Int,Int,Int)):(Int,Int,Int,Int) = 
	{
		val power:Int = 4; // p r e f e r a b l y  even ( 4 )
		val pN : Int = if(pt._1 > 0) Math.pow(Math.abs(pt._3-pt._1-1), power).asInstanceOf[Int] else 0;
		val pS : Int = if(pt._1 < plat.platx - 1) Math.pow(Math.abs(pt._3-pt._1+1), power).asInstanceOf[Int] else 0;
		val pE : Int = if(pt._2 < plat.platy - 1) Math.pow(Math.abs(pt._4-pt._2+1), power).asInstanceOf[Int] else 0;
		val pW : Int = if(pt._2 > 0) Math.pow(Math.abs(pt._4-pt._2-1), power).asInstanceOf[Int] else 0;
		Tuple4(pN,pS,pE,pW)
	}
	
	def collision_aversion_ranges(range : (Int, Int, Int, Int)) : (Int, Int, Int, Int) = 
	{
		val rN : Int = if(pos._1==0) 0 else{if(plat.platgrid(pos._1-1)(pos._2) != -1) {println("\n\t\tPOTENTIAL COLLISION AVERTED BETWEEN " + id +" and " + plat.platgrid(pos._1-1)(pos._2) + "\n");0} else range._1};
		val rS : Int = if(pos._1== (plat.platx - 1)) 0 else{if(plat.platgrid(pos._1+1)(pos._2) != -1) {println("\n\t\tPOTENTIAL COLLISION AVERTED BETWEEN " + id +" and " + plat.platgrid(pos._1+1)(pos._2) + "\n");0} else range._2};
		val rE : Int = if(pos._2== (plat.platy - 1)) 0 else{if(plat.platgrid(pos._1)(pos._2 + 1) != -1) {println("\n\t\tPOTENTIAL COLLISION AVERTED BETWEEN " + id +" and " + plat.platgrid(pos._1)(pos._2+1) + "\n");0} else range._3};
		val rW : Int = if(pos._2==0) 0 else{if(plat.platgrid(pos._1)(pos._2 - 1) != -1) {println("\n\t\tPOTENTIAL COLLISION AVERTED BETWEEN " + id +" and " + plat.platgrid(pos._1)(pos._2 - 1) + "\n");0} else range._4};
		Tuple4(rN,rS,rE,rW)
	}

}

class passinfo(){
	var list:List[passenger] = List();
}
