// APPLETS // \\ SPOTnCLICK GAME \\
/*
   Applet Size : 1100 x 700
   Screen Size : 1000 x 600
*/
import java.applet.*;
import java.awt.*;
import java.awt.event.*;
import java.util.*;
import java.lang.Math;
public class RB28 extends Applet implements MouseListener , ActionListener
{
 int delay , x , y , a , b , n , clickdelay , clicks , size;
 long score;
 Button bt;
 Calendar c;
 boolean clicked;
 int t1 , t2;
 void ini()
 {
  delay = 30;
  x = y = a = b = 0;
  n = 0;
  clicks = 0;
  size = 50;
  clickdelay = 0;
  bt = new Button("PLAY AGAIN !");
  c = Calendar.getInstance();
  clicked = false;
  t1 = t2 = 0;
  score = 0;
 }
 public void init()
 {
  ini();
  add(bt);
  bt.addActionListener(this);
  addMouseListener(this);
 }
 public void actionPerformed(ActionEvent ae)
 {
  ini();
  repaint();
 }
 public void mouseEntered(MouseEvent me)
 {
 }
 public void mouseExited(MouseEvent me)
 {
 }
 public void mousePressed(MouseEvent me)
 {
 }
 public void mouseReleased(MouseEvent me)
 {
 }
 public void mouseClicked(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  if(x <= a + size && y <= b + size)
  {
   clicks += 10;
   clicked = true;
  }
  else
  clicks -= 1;
  t1 = 1000 * c.get(Calendar.SECOND) + c.get(Calendar.MILLISECOND);
  repaint();
 }
 public void paint(Graphics g)
 {
  g.drawRect(50 , 50 , 1000 , 600);
  if(n < 30)
  {
   while(!(a < 1050 - size && a > size + 1))
   a = (int) (1000 * Math.random());
   while(!(b < 650 - size && b > size + 1))
   b = (int) (1000 * Math.random());
   g.setColor(Color.black);
   g.fillRect(a , b , size , size);
   t2 = 1000 * c.get(Calendar.SECOND) + c.get(Calendar.MILLISECOND);
   clickdelay = clicked ? (t1 - t2) : 5000;
   g.setColor(Color.white);
   for(int i = 0;i <= 1000 * delay;i++)
   g.drawRect(1 , 1 , 9 , 9);
   g.fillRect(a , b , size , size);
   score += (5000 - clickdelay) * clicks;
   showStatus("SCORE = " + score);
   clicked = false;
   clicks = 0;
   n++;
   delay--;
   repaint();
  }
 }
}
