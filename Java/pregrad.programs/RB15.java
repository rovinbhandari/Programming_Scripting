// APPLETS //
import java.awt.*;
import java.applet.*;
public class RB15 extends Applet
{
 int a,b,c,d;
 public void init()
 {
  b = -269;
  c = d = 1;
 }
 public void paint(Graphics g)
 {                        
  g.setColor(Color.red);
  g.fillOval(100,100,600,600);
  g.setColor(Color.orange);
  for(int e = -269;e >= -629 ;e -= 6)
  {
   g.fillArc(100,100,600,600,e,2);
  }
  while(d <= 134)
  {
   d++;
   if(b == -629)
   {
    b = -269;
    c++;
   }
   if(c % 2 == 0)
   {
    g.setColor(Color.blue);
   }
   else
   {
    g.setColor(Color.green);
   }
   g.fillArc(100,100,600,600,b,2);
   for(a = 1;a <= 24000;a++)
   {
    g.fillOval(96,96,8,8);
    g.fillOval(696,96,8,8);
    g.fillOval(96,696,8,8);
    g.fillOval(696,696,8,8);
   }
   g.setColor(Color.orange);
   g.fillArc(100,100,600,600,b,2);
   b -= 6;
  }
 }
}
