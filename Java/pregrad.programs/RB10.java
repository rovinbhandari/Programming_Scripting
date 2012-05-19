// APPLETS //
import java.awt.*;
import java.applet.*;
public class RB10 extends Applet
{
 TextField q1,q2;
 double d1,d2,d3;
 public void init()
 {
  d1 = d2 = d3 = 0.0d;
  q1 = new TextField(16);
  q2 = new TextField(16);
  add(q1);
  add(q2);
  q1.setText("0.0");
  q2.setText("0.0");
 }
 public void paint(Graphics g)
 {
  g.drawString("Input two numbers to add" , 10 , 50);
  d1 = Double.parseDouble(q1.getText());
  d2 = Double.parseDouble(q2.getText());
  d3 = d1 + d2;
  g.drawString("Sum = " + d3 , 10 , 100);
  for(int i = 1 ; i <= 400000 ; i++)
  {
   repaint();
  }
 }
}
