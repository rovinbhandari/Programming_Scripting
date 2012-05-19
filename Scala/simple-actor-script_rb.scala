// code-examples/Concurrency/simple-actor-script.scala
import java.lang._;
import scala.actors.Actor;

class Redford extends Actor {
  def act() = {
  	//Thread.sleep(1300);
    println("A lot of what acting is, is paying attention.");
  }
}

val robert = new Redford;
robert.start;
//Thread.sleep(100);
println("yoohoo!");
Thread.sleep(100);
