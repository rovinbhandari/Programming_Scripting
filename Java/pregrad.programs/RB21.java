// APPLETS //       // include an UNDO function  //
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class RB21 extends Applet implements MouseListener , MouseMotionListener , ActionListener
{
 int c,n,x,y,X1,Y1,X2,Y2;
 boolean b1,b2;
 int [] X,Y,A,B;
 Button b;
 public void init()
 {
  b = new Button("Click to Clear");
  b1 = b2 = false;
  X1 = Y1 = X2 = Y2 = x = y = 0;
  c = 1;
  n = 2;
  X = new int[n];
  Y = new int[n];
  A = new int[n];
  B = new int[n];
  addMouseListener(this);
  addMouseMotionListener(this);
  add(b);
  b.addActionListener(this);
 }
 public void actionPerformed(ActionEvent ae)
 {
  X1 = Y1 = X2 = Y2 = x = y = 0;
  c = 1;
  n = 2;
  X = Y = A = B = new int[n];
  b2 = true;
  b1 = false;
  repaint();
 }
 public void mousePressed(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE PRESSED AT " + x + " , " + y);
 }
 public void mouseReleased(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE RELESED AT " + x + " , " + y);
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
  if((x < 1050 && x > 50) && ( y > 50 && y < 650))
  {
   b1 = true;
   System.arraycopy(X,0,A,0,n-2);
   System.arraycopy(Y,0,B,0,n-2);
   X = new int[n+1];
   Y = new int[n+1];
   System.arraycopy(A,0,X,0,n-2);
   System.arraycopy(B,0,Y,0,n-2);
   X[n-2] = x;
   Y[n-2] = y;
   A = new int[n+1];
   B = new int[n+1];
   if(c != 1)
   {
    repaint();
   }
   c++;
   n++;
  }
 }
 public void mouseMoved(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE CURRENTLY AT " + x + " , " + y);
 }
 public void mouseDragged(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE BEING DRAGGED AT " + x + " , " + y);
 }
 public void paint(Graphics g)
 {
  g.drawRect(50,50,1000,600);
  if(b1 & (!b2))
  {
   g.setColor(Color.red);
   for(int i = 0;i < (n - 3);i++)
   {
    X1 = X[i];
    Y1 = Y[i];
    X2 = X[i+1];
    Y2 = Y[i+1];
    g.drawLine(X1,Y1,X2,Y2);
   }
  }
  b1 = b2 = false;
 }
}
