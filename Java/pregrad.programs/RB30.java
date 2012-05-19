// APPLETS //
import java.awt.*;
import java.applet.*;
public class RB30 extends Applet
{
 int n , dia;
 int x , y;
 public void init()
 {
  n = 1;
  x = 899;
  y = 200;
  dia = 300;
 }
 public void paint(Graphics g)
 {
  g.setColor(Color.green);
  g.drawLine(100 , y + dia + 1 , 1100 , y + dia + 1);
  while(n <= 455)
  {
   g.setColor(Color.black);
   g.fillOval(x , y , dia , dia);
   g.setColor(Color.white);
   for(int i = 1;i <= 5;i++)
   g.fillArc(x + 5 , y + 5 , dia - 10 , dia - 10 , n + (i - 1) * 72 , 68);
   for(int i = 0;i < 5000;i++)
   g.drawRect(1 , 1 , 11 , 11);
   g.fillOval(x , y , dia , dia);
   n++;
   x -= 2;
  }
 }
}
