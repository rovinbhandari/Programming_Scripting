class RB23
{
 int x,y;
 String s;
 RB23(int a , int b)
 {
  x = a;
  y = b;
 }
 public String toString()
 {
  s = x + " + i" + y;
  return(s);
 }
}
class RB23a
{
 public static void main(String args[])
 {
  RB23 r = new RB23(5 , 6);
  System.out.println(r);
 }
}
