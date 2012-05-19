// APPLETS //
import java.awt.*;
import java.applet.*;
public class RB11 extends Applet
{
 int i = 0;
 public void paint(Graphics g)
 {
  g.fillRect(50 , i , 50 , 50);
  i++;
  if(i == 651)
  {
   i = 0;
  }
  for(int j = 1 ; j <= 84000 ; j++)
  {
   repaint();
  }
 }
}
