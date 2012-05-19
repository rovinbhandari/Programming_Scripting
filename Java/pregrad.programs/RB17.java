// APPLETS //
import java.awt.*;
import java.applet.*;
import java.awt.event.*;
public class RB17 extends Applet implements KeyListener , MouseListener
{
 char d;
 String s,c;
 int i,j,k,x,y;
 public void init()
 {
  i = k = 0;
  s = c = "";
  addKeyListener(this);
  addMouseListener(this);
 }
 public void mousePressed(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE PRESSED at " + x + " , " + y);
 }
 public void mouseReleased(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE RELEASED at " + x + " , " + y);
 }
 public void mouseClicked(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE CLICKED at " + x + " , " + y);
  if((x >= 10 && x <= 100) && (y >= 10 && y <= 30))
  {
   k = 1;
  }
  if((x >= 110 && x <= 200) && (y >= 10 && y <= 30))
  {
   k = 0;
  }
  if((x >= 210 && x <= 300) && (y >= 10 && y <= 30))
  {
   k = 2;
  }
 }
 public void mouseEntered(MouseEvent me)
 {
  showStatus("MOUSE ENTERED");
 }
 public void mouseExited(MouseEvent me)
 {
  showStatus("MOUSE EXITED");
 }
 public void keyPressed(KeyEvent ke)
 {
  showStatus("KEY PRESSED");
 }
 public void keyReleased(KeyEvent ke)
 {
  showStatus("KEY RELEASED");
 }
 public void keyTyped(KeyEvent ke)
 {
  c = "";
  d = ke.getKeyChar();
  c = c + d;
  if(k == 2)
  {
   if((s.equals("")) || (s.charAt(s.length() - 1) == ' '))
   {
    c = c.toUpperCase();
   }
   else
   {
    c = c.toLowerCase();
   }
  }
  if(k == 1)
  {
   c = c.toUpperCase();
  }
  if(k == 0)
  {
   c = c.toLowerCase();
  }
  s = s + c;
  i = s.length() / 100;
  repaint(50,50 + i * 20,1250,30);
  if(i == 0)
  {
   j = 0;
  }
  else
  {
   j = 100 * i - 1;
  }
 }
 public void paint(Graphics g)
 {
  g.setColor(Color.orange);
  g.fillRect(10,10,90,30);
  g.fillRect(110,10,90,30);
  g.fillRect(210,10,90,30);
  g.setColor(Color.black);
  g.drawString("UPPER CASE" , 15 , 30);
  g.drawString("lower case" , 124 , 30);
  g.drawString("Title Case" , 224 , 30);
  g.drawString(s.substring(j),70,50 + i * 20 + 15);
 }
}
