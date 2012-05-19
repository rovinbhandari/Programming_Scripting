// APPLETS //
import java.awt.*;
import java.applet.*;
import java.awt.event.*;
public class RB16 extends Applet implements KeyListener
{
 String s;
 int i,j;
 public void init()
 {
  i = 0;
  s = "";
  addKeyListener(this);
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
  s = s + ke.getKeyChar();
  i = s.length() / 80;
  repaint(50,50 + i * 20,1220,30);
  if(i == 0)
  {
   j = 0;
  }
  else
  {
   j = 80 * i - 1;
  }
 }
 public void paint(Graphics g)
 {
  g.drawString(s.substring(j),70,50 + i * 20 + 15);
 }
}
