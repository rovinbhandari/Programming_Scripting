// APPLETS //
import java.awt.*;
import java.applet.*;
public class RB14 extends Applet
{
 int a,b,c,d;
 public void init()
 {
  b = 0;
  c = d = 1;
 }
 public void paint(Graphics g)
 {
  g.setColor(Color.green);
  g.fillOval(100,100,600,600);
  while(d <= 1234)
  {
   d++;
   if(b == 360)
   {
    b = 0;
    c++;
   }
   if(c % 2 == 0)
   {
    g.setColor(Color.blue);
   }
   else
   {
    g.setColor(Color.orange);
   }
   g.fillArc(100,100,600,600,b,1);
   b++;
   for(a = 1;a <= 4000;a++)
   {
    g.fillOval(96,96,8,8);
    g.fillOval(696,96,8,8);
    g.fillOval(96,696,8,8);
    g.fillOval(696,696,8,8);
   }
  }
 }
}
