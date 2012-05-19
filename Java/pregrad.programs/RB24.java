import java.lang.Math;
class RB24
{
 String s;
 StringBuffer sb;
 int a[][] = new int[4][4];
 RB24()
 {
  double d;
  for(int i = 0;i < 4;i++)
  {
   for(int j = 0;j < 4;j++)
   {
    d = Math.random();
    d *= 100;
    a[i][j] = (int) d;
   }
  }
 }
 public void test()
 {
  System.out.println("test run");
 }
 public String t()
 {
  return("test");
 }
 public String toString()
 {
  sb = new StringBuffer(84);
  s = "";
  int x;
  for(int i = 0;i < 4;i++)
  {
   for(int j = 0;j < 4;j++)
   {
    x = a[i][j];
    sb.append(x).append(" ");
   }
   sb.append('\n');
  }
  s = sb.toString();
  return(s);
 }
}
class RB24a
{
 public static void main(String args[])
 {
  RB24 r1 = new RB24();
  System.out.print(r1);
  r1.test();
  System.out.print(r1);
  r1.test();
  RB24 r2 = new RB24();
  r2.test();
  System.out.print(r2);
  r2.test();
  System.out.println(r2.t());
 }
}
