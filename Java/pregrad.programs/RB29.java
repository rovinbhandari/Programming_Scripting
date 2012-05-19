// APPLETS //
/*
  Applet Size : 900 x 600
*/
import java.awt.*;
import java.applet.*;
import java.lang.Math;
public class RB29 extends Applet
{
 int a , b , c , d , dia , a1 , b1 , c1 , d1;
 int i , j , k , l , p;
 public void init()
 {
  a = b = 0;
  c = 600;
  d = 500;
  i = j = k = l = p = 1;
  dia = 71;
 }
 public void paint(Graphics g)
 {
  while(p <= 15000)
  {
   a1 = a + dia / 2 + 1;
   b1 = b + dia / 2 + 1;
   c1 = c + dia / 2 + 1;
   d1 = d + dia / 2 + 1;
   g.setColor(Color.red);
   g.fillOval(a , b , dia , dia);
   g.setColor(Color.black);
   g.fillOval(c , d , dia , dia);
   g.setColor(Color.white);
   for(int x = 1;x <= 2800;x++)
   {
    g.drawRect(1 , 1 , 1 , 1);
   }
   g.fillOval(a , b , dia , dia);
   g.fillOval(c , d , dia , dia);
   if( a > 900 - dia - 1)
   {
    i = -1;
   }
   if(a < 1)
   {
    i = 1;
   }
   if(b > 600 - dia - 1)
   {
    j = -1;
   }
   if(b < 1)
   {
    j = 1;
   }
   if(c > 900 - dia - 1)
   {
    k = -1;
   }
   if(c < 1)
   {
    k = 1;
   }
   if(d > 600 - dia - 1)
   {
    l = -1;
   }
   if(d < 1)
   {
    l = 1;
   }
   if(collision())
   {
    i *= -1;
    j *= -1;
    k *= -1;
    l *= -1;
   }
   a += i;
   b += j;
   c += k;
   d += l;
   p++;
  }
 }
 boolean collision()
 {
  int dist = (int) (Math.sqrt(((a1 - c1) * (a1 - c1)) + ((b1 - d1) * (b1 - d1))));
  if(dist <= dia)
  {
   return (true);
  }
  return (false);
 }
}
