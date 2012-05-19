// APPLETS //
import java.awt.*;
import java.applet.*;
public class RB13 extends Applet
{
 int i,j,n,a,b;
 public void init()
 {
  a = i = 0;
  b = j = n = 1;
 }
 public void paint(Graphics g)
 {
  while(n <= 8000)
  {
   n++;
   g.setColor(Color.yellow);
   i += j;
   a += b;
   g.fillOval(a , i , 50 , 50);
   if(i <= 0)
   {
    j = 1;
   }
   if(i >= 350)
   {
    j = -1;
   }
   if(a <= 0)
   {
    b = 1;
   }
   if(a >= 400)
   {
    b = -1;
   }
   g.setColor(Color.white);
   for(int k = 1 ; k <= 1000 ; k++)
   {
    g.drawRect(1,1,4,4);
   }
   g.fillRect(a , i , 50 , 50);
  }
 }
}
