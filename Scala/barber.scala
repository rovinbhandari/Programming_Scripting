import scala.actors._;
import scala.actors.Actor._;
import scala.actors.Actor;
import java.lang._;



class customer extends Actor
{
	def act() = 
	{
		loop
		{
			react
			{
				case s : String => println(s + " Done");
			}
		}
	}
}



		val cust1 : customer = new customer();
		cust1.start;
		val cust2 : customer = new customer();
		cust2.start;
		val cust3 : customer = new customer();
		cust3.start;
		val cust4 : customer = new customer();
		cust4.start;
		
		val custgrp : customer = new customer();
		custgrp.start;
		
		

		cust1 ! "haircut1";
		//Thread.sleep(200);
		cust2 ! "haircut2";
		cust1 ! "haircut1";
		cust2 ! "haircut2";
		//Thread.sleep(600);
		//cust.finish;
		
		cust3 ! "haircut3";
		//Thread.sleep(200);
		cust4 ! "haircut4";
		cust3 ! "haircut3";
		cust4 ! "haircut4";
		//Thread.sleep(600);
		//cust.finish;
		
		custgrp ! "haircut grp1";
		custgrp ! "haircut grp2";
		custgrp ! "haircut grp3";
		custgrp ! "haircut grp2";
		custgrp ! "haircut grp1";
		custgrp ! "haircut grp3";
		custgrp ! "haircut grp1";
		custgrp ! "haircut grp3";
		
		
		
		Thread.sleep(1200);
		
		
		
		System.exit(0);



