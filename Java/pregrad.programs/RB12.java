// APPLETS //
import java.awt.*;
import java.applet.*;
public class RB12 extends Applet
{
 int i,j,k;          // k inroduced to terminate the program // otherwise while(true){...} can be used
 public void init()  
 {
  i = 0;
  j = k = 1;
 }
 public void paint(Graphics g)
 {
  while(k <= 3000)
  {
   k++;
   i += j;
   g.setColor(Color.yellow);
   g.fillOval(50 , i , 50 , 50);
   if(i <= 0)
   {
    j = 1;
   }
   if(i >= 650)
   {
    j = -1;
   }
   g.setColor(Color.white);
   for(int j = 1 ; j <= 1000 ; j++)
   {
    g.drawRect(1,1,4,4);
   }
   g.fillOval(50 , i , 50 , 50);
  }
 }
}
