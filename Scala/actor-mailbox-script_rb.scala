// code-examples/Concurrency/actor-mailbox-script.scala
import java.lang._;
import scala.actors.Actor;
import scala.actors.Actor._;

val countActor = actor {
  loop {
  	
    react {
      case "how many?" => {
      
        println("I've got " + mailboxSize.toString + " messages in my mailbox.");
      
      }
    }
  }
}

countActor ! 1
countActor ! 2
countActor ! 3
countActor ! "how many?"

Thread.sleep(100);

countActor ! "how many?"

Thread.sleep(100);

countActor ! 4
countActor ! "how many?"

// Comment all the sleep statements above to witness wierd behaviour.
Thread.sleep(100);
