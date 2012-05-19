/* APPLETS */

import java.awt.*;
import java.applet.*;
public class t1 extends Applet
{
 String str;
 public void init()
 {
  str = getParameter("string");
  if(str==null)
  str="JAVA";
  str="Hello "+str;
 }
 public void paint(Graphics g)
 {
  g.drawString(str, 2, 20);
  g.drawString("Welcome", 40 , 40);
 }
}

