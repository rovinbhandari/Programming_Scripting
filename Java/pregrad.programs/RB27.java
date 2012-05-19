// APPLETS //
import java.awt.*;
import java.applet.*;
/*
     Applet size : 1200 x 710
     Larger box  : 1000 x 600
     Smaller box :  250 x 160
     Ball size   :   15 x 15
*/
public class RB27 extends Applet
{
 int a , b , c , d , e , f;
 int i , j , k , l , m , n , p , q;
 public void init()
 {
  a = b = c = d = e = f = 0;
  i = j = k = l = m = n = p = q = 1;
  setBackground(Color.gray);
 }
 public void paint(Graphics g)
 {
  a = b = 50;
  c++;
  d++;
  e++;
  f++;
  while(p <= 600)
  {
   g.setColor(Color.red);
   g.drawRect(a , b , 1000 , 600);
   g.fillRect(a + c , b + d , 250 , 160);
   g.setColor(Color.black);
   g.fillOval(a + c + e , b+ d + f , 15 , 15);
   g.setColor(Color.gray);
   for(int x = 1;x <= 3500;x++)
   {
    g.drawRect(1 , 1 , 10 , 10);
   }
   g.fillRect(a + c , b + d , 250 , 160);
//   g.drawRect(a , b , 1000 , 600);
   if(c > 1000 - 250 - 1)
   {
    k = -1;
   }
   if(c < 2)
   {
    k = 1;
   }
   c += k;
   if(d > 600 - 160 - 1)
   {
    l = -1;
   }
   if(d < 2)
   {
    l = 1;
   }
   d += l;
   if(e > 250 - 15 - 1)
   {
    m = -1;
   }
   if(e < 2)
   {
    m = 1;
   }
   e += m;
   if(f > 160 - 15 - 1)
   {
    n = -1;
   }
   if(f < 2)
   {
    n = 1;
   }
   f += n;
/*   if(a > 1200 - 1000 - 1)
   {
    i = -1;
   }
   if(a < 2)
   {
    i = 1;
   }
   a += i;
   if(b > 710 - 600 - 1)
   {
    j = -1;
   }
   if(b < 2)
   {
    j = 1;
   }
   b += j;
 */
   p++;
  }
 }
}
