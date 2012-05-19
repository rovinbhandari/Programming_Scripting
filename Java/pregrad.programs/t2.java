/* AAPLETS */
import java.awt.*;
import java.applet.*;
public class t2 extends Applet
{
 TextField q1,q2;
 double d1,d2,d3;
 int i = 0;
 public void init()
 {
  q1=new TextField(16);
  q2=new TextField(16);
  add(q1);
  add(q2);
//  q1.addActionListener();
//  q2.addActionListener();
  q1.setText("0.0");
  q2.setText("0.0");
  d1=d2=d3=0.0d;
 }
 public void paint(Graphics g)
 {
  d1=Double.parseDouble(q1.getText());
  d2=Double.parseDouble(q2.getText());
  g.drawString("Enter two numbers to add",5,45);
  d3=d1+d2;
  g.drawString("Sum is : "+String.valueOf(d3),5,70);
  for(i=0;i<=80000;i++)
  repaint();
 }
/* public boolean actionPerformed(Event event, Object obj)
 {
  repaint();
  return true;
 }*/
}
