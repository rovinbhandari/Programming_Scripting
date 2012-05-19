// APPLETS // Cursor Graphics //    // store in array //
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class RB19 extends Applet implements MouseListener , MouseMotionListener
{
 String s1,s2;
 int x,y,i,a,a1,a2,X1,Y1,X2,Y2;
 boolean b,b1,b2;
 public void init()
 {
  b = b1 = b2 = false;
  s1 = "";
  s2 = "";
  X1 = Y1 = X2 = Y2 = x = y = i = a = a1 = a2 = 0;
  addMouseListener(this);
  addMouseMotionListener(this);
 }
 public void mousePressed(MouseEvent me)
 {
  a1 = me.getX();
  a2 = me.getY();
  showStatus("MOUSE PRESSED AT " + a1 + " , " + a2);
 }
 public void mouseReleased(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE RELESED AT " + x + " , " + y);
  X1 = (a1 < x) ? a1 : x;
  Y1 = (a2 < y) ? a2 : y;
  X2 = (a1 > x) ? a1 : x;
  Y2 = (a2 > y) ? a2 : y;
  repaint(X1,Y1,X2-X1,Y2-Y1);
 }
 public void mouseEntered(MouseEvent me)
 {
  showStatus("MOUSE ENTERED");
 }
 public void mouseExited(MouseEvent me)
 {
  showStatus("MOUSE EXITED");
 }
 public void mouseClicked(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE CLICKED AT " + x + " , " + y);
  b1 = true;
  if(!((x < 1050 && x > 50) && ( y > 50 && y < 650)))
  {
   repaint();
  }
 }
 public void mouseMoved(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE CURRENTLY AT " + x + " , " + y);
/*  b1 = true;
  repaint(); 
*/ }
 public void mouseDragged(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE BEING DRAGGED AT " + x + " , " + y);
  X1 = (a1 < x) ? a1 : x;
  Y1 = (a2 < y) ? a2 : y;
  X2 = (a1 > x) ? a1 : x;
  Y2 = (a2 > y) ? a2 : y;
  repaint(X1,Y1,X2-X1,Y2-Y1);
 }
 public void paint(Graphics g)
 {
  g.drawString("Click outside the box to clear",20,20);
  g.drawRect(50,50,1000,600);
  if((x < 1050 && x > 50) && ( y > 50 && y < 650))
  {
   b = true;
  }
  else
  {
   b = false;
  }
  while(!b & b1)
  {
   Color c = new Color(30 + 25 * i, 255 - 15 * i,100 + 16 * i);
   g.setColor(c);
   g.fillRect(x,y,(i+2)*10,(i+2)*10);
   for(int j = 0;j < 16000;j++)
   {
    g.fillRect(x,y,10,10);
   }
   i++;
   if(i == 9)
   {
    g.setColor(Color.black);
    g.drawString("CLAERED",x+12,y+48);
    break;
   }
  }
  b1 = false;
  i = 0;
  if(b)
  {
   g.setColor(Color.gray);
   g.fillRect(X1,Y1,X2-X1,Y2-Y1);
  } 
 }
}
