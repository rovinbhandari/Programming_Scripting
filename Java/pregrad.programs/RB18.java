// APPLETS //
import java.applet.*;
import java.awt.*;
import java.awt.event.*;
public class RB18 extends Applet implements MouseListener
{
 int x,y,a,b;
 public void init()
 {
  x = y = a = b = 0;
  addMouseListener(this);
  setBackground(Color.gray);
 }
 public void mousePressed(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE PRESSED AT " + x + " " + y);
 }
 public void mouseReleased(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE RELEASED AT " + x + " " + y);
 }
 public void mouseClicked(MouseEvent me)
 {
  
 }
 public void mouseEntered(MouseEvent me)
 {
 }
 public void mouseExited(MouseEvent me)
 {
 }
 //public void caption
 public void paint(Graphics g)
 {
  for(int j =0;j<10;j++)
 {
  g.setColor(Color.white);
  g.drawLine(10,10,10,40);
  g.drawLine(10,10,100,10);
  g.setColor(Color.black);
  g.drawLine(10,40,100,40);
  g.drawLine(100,40,100,10);
  for(long i = 0;i<=66666666;i++);
  g.setColor(Color.black);
  g.drawLine(10,10,10,40);
  g.drawLine(10,10,100,10);
  g.setColor(Color.white);
  g.drawLine(10,40,100,40);
  g.drawLine(100,40,100,10);
  for(long i = 0;i<=66666666;i++);
 }
 }
}



