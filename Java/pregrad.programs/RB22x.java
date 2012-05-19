//  APPLETS  //  |||  //  TIC-TAC-TOE  //
import java.applet.*;
import java.awt.*;
import java.awt.event.*;
public class RB22x extends Applet implements MouseListener , ActionListener
{
 char grid[][];
 int x , y , a , b;
 boolean validturn , player , ended;
 char c;
 Font f;
 Button bt;
 public void ini()
 {
  x = y = 0;
  a = b = 8;  // random value > 3
  c = 'O';
  grid = new char[3][3];
  for(int i = 0;i < 3;i++)
  {
   for(int j = 0;j < 3;j++)
   {
    grid[i][j] = '0';
   }
  }
  validturn = player = ended = false;
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
  outer : for(int i = 0;i < 3;i++)
  {
   for(int j = 0;j < 3;j++)
   {
    if((x > (51 + j * 35)) && (x < (51 + j * 35 + 30)) && (y > (151 + i * 35)) && (y < (151 + i * 35 + 30)))
    {
     a = i;
     b = j;
     break outer;
    }
   }
  }
  if((a < 3) && (grid[a][b] == '0') && !(ended))
  {
   validturn = true;
   player = !(player);
   repaint();
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
  showStatus("Player" + ((player) ? "2" : "1") + " Turn");
  t3play(g);
 }
 public void t3play(Graphics h)
 {
  c = !(player) ? 'X' : 'O';
  grid[a][b] = c;
  t3printXO(h);
  if(t3equal(grid[0][0] , grid[1][1] , grid[2][2]) || t3equal(grid[0][2] , grid[1][1] , grid[2][0]) || t3equal(grid[0][0] , grid[0][1] , grid[0][2]) || t3equal(grid[0][0] , grid[1][0] , grid[2][0]) || t3equal(grid[1][0] , grid[1][1] , grid[1][2]) || t3equal(grid[0][1] , grid[1][1] , grid[2][1]) || t3equal(grid[2][0] , grid[2][1] , grid[2][2]) || t3equal(grid[0][2] , grid[1][2] , grid[2][2]))
  {
   t3declarewinner();
  }
 }
 public boolean t3equal(char p , char q , char r)
 {
  if((p != '0') && (q != '0') && (r != '0'))
  {
   if((p == q) && (q == r) && (r == p))
   {
    return (true);
   }
  }
  return (false);
 }
 public void t3printXO(Graphics h)
 {
  for(int i = 0;i < 3;i++)
  {
   for(int j = 0;j < 3;j++)
   {
    if(grid[i][j] == '0')
    {
     continue;
    }
    h.drawString("" + grid[i][j] , 51 + j * 35 + 5 , 151 + i * 35 + 25);
   }
  }
 }
 public void t3declarewinner()
 {
  showStatus("Player" + (!(player) ? "2" : "1") + " Wins");
  ended = true;
 }
}
