//  MUST SEE RB22x.java  //

//  APPLETS  //  |||  //  TIC-TAC-TOE  //
import java.applet.*;
import java.awt.*;
import java.awt.event.*;
public class RB22 extends Applet implements MouseListener , ActionListener
{
 char grid[][];
 char [] win1 , win2;
 int x , y , a , b;
 String region;
 boolean clicked , validturn , player , win;
 char c , d;
 Font f;
 Button bt;
 public void ini()
 {
  x = y = a = b = 0;
  c = 'O';
  d = 11;
  grid = new char[3][3];
  for(int i = 0;i < 3;i++)
  {
   for(int j = 0;j < 3;j++)
   {
    grid[i][j] = d;
    d += 5;
   }
  }
  win1 = new char[3];
  win2 = new char[3];
  region = "";
  clicked = validturn = player = win = false;
  f = new Font(getParameter("fontname"),Font.BOLD,Integer.parseInt(getParameter("fontsize")));
  bt = new Button("PLAY AGAIN !");
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
  clicked = validturn = true;
  if((x > 50 && x < 80) && (y > 150 && y < 180))
  {
   region = "001";
  }
  else if((x > 85 && x < 115) && (y > 150 && y < 180))
  {
   region = "012";
  }
  else if((x > 120 && x < 150) && (y > 150 && y < 180))
  {
   region = "023";
  }
  else if((x > 50 && x < 80) && (y > 185 && y < 215))
  {
   region = "104";
  }
  else if((x > 85 && x < 115) && (y > 185 && y < 215))
  {
   region = "115";
  }
  else if((x > 120 && x < 150) && (y > 185 && y < 215))
  {
   region = "126";
  }
  else if((x > 50 && x < 80) && (y > 220 && y < 250))
  {
   region = "207";
  }
  else if((x > 85 && x < 115) && (y > 220 && y < 250))
  {
   region = "218";
  }
  else if((x > 120 && x < 150) && (y > 220 && y < 250))
  {
   region = "229";
  }
  else
  {
   validturn = false;
  }
  if(validturn)                                        
  {
   c = (player) ? 'X' : 'O';
   t3repaintregion(Integer.parseInt("" + region.charAt(2)));
  }
 }
 public void t3repaintregion(int q)
 {
  switch(q)
  {
   case 1 : repaint(50 , 150 , 30 , 30);
   break;
   case 2 : repaint(85 , 150 , 30 , 30);
   break;
   case 3 : repaint(120 , 150 , 30 , 30);
   break;
   case 4 : repaint(50 , 185 , 30 , 30);
   break;
   case 5 : repaint(85 , 185 , 30 , 30);
   break;
   case 6 : repaint(120 , 185 , 30 , 30);
   break;
   case 7 : repaint(50 , 220 , 30 , 30);
   break;
   case 8 : repaint(85 , 220 , 30 , 30);
   break;
   case 9 : repaint(120 , 220 , 30 , 30);
   break;
  }
 }
 public void paint(Graphics g)
 {
  g.setFont(f);
  g.drawRoundRect(50,150,99,99,20,20);
  g.fillRoundRect(80,150,5,100,20,20);
  g.fillRoundRect(115,150,5,100,20,20);
  g.fillRoundRect(50,180,100,5,20,20);
  g.fillRoundRect(50,215,100,5,20,20);
  showStatus("Player" + ((t3turn()) ? "2" : "1") + " Turn");
  if(validturn)
  {
   t3play(g);
  }
 }
 public boolean t3turn()
 {
  if(validturn)
  {
   return (!player);
  }
  else
  {
   return (player);
  }
 }
 public void t3play(Graphics h)
 {
  grid[Integer.parseInt("" + region.charAt(0))][Integer.parseInt("" + region.charAt(1))] = c;
  t3printXO(h , Integer.parseInt("" + region.charAt(2)));
  win = t3win();
  if(win)
  {
   t3declarewinner();
  }
  else
  {
   player = t3turn();
   validturn = false;
   clicked = false;
  }
 }
 public boolean t3win()
 {
  win1 = new char[3];
  win2 = new char[3];
  for(int i = 0;i < 3;i++)
  {
   for(int j = 0; j < 3;j++)
   {
    win1[j] = grid[i][j];
    win2[j] = grid[j][i];
    if(t3equal(win1[0] , win1[1] , win1[2]) || t3equal(win2[0] , win2[1] , win2[2]) || t3equal(grid[0][0] , grid[1][1] , grid[2][2]) || t3equal(grid[0][2] , grid[1][1] , grid[2][0]))
    {
     return (true);
    }
   }
  }
  return (false);
 }
 public boolean t3equal(char a , char b , char c)
 {
  if((a == b) && (b == c) && (c == a))
  {
   return (true);
  }
  else
  {
   return (false);
  }
 }
 public void t3printXO(Graphics h , int e)
 {
  switch(e)
  {
   case 1 : a = 55;
            b = 175;
   break;
   case 2 : a = 90;
            b = 175;
   break;
   case 3 : a = 125;
            b = 175;
   break;
   case 4 : a = 55;
            b = 210;
   break;
   case 5 : a = 90;
            b = 210;
   break;
   case 6 : a = 125;
            b = 210;
   break;
   case 7 : a = 55;
            b = 245;
   break;
   case 8 : a = 90;
            b = 245;
   break;
   case 9 : a = 125;
            b = 245;
   break;
  } 
  h.drawString("" + c , a , b);
 }
 public void t3declarewinner()
 {
  showStatus("Player" + ((player) ? "2" : "1") + " Wins");
 }
}
