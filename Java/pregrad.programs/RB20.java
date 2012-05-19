// APPLETS // Cursor Graphics //   // save images in buffer and repaint them to avoid erasing y mouse//
import java.awt.*;
import java.awt.event.*;
import java.applet.*;
public class RB20 extends Applet implements MouseListener , MouseMotionListener
{
 int x,y,a;
 public void init()
 {
  y = x = a = 0;
  addMouseListener(this);
  addMouseMotionListener(this);
 }
 public void mousePressed(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE PRESSED AT " + x + " , " + y);
  repaint(x,y,50,50);
 }
 public void mouseReleased(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE RELESED AT " + x + " , " + y);
  repaint(x,y,50,50);
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
 }
 public void mouseMoved(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  showStatus("MOUSE CURRENTLY AT " + x + " , " + y);
  repaint(x,y,50,50);
 }
 public void mouseDragged(MouseEvent me)
 {
  x = me.getX();
  y = me.getY();
  a = (a + 1) % 15;
  showStatus("MOUSE BEING DRAGGED AT " + x + " , " + y);
  h.fillRect(50,50,50,50);
  repaint(x,y,50,50);
 }
 public void paint(Graphics g)
 {
  g.fillRect(x+16+a,y+16+a,20,20);
 }
}
