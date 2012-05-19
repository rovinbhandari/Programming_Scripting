// code-examples/Concurrency/factory-actor-script.scala
import java.lang._;
import scala.actors.Actor
import scala.actors.Actor._

val paulNewman = actor {
  println("To be an actor, you have to be a child.")
}

Thread.sleep(100);
