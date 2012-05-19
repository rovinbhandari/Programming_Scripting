import java.lang.Math;
class temp4
{
 double h,p,b;
 temp4(double x,double y)
 {
  h = x;
  b=y;
  p=Math.sqrt((h*h)-(b*b));
  System.out.println(p);
 }
}
class t
{
 public static void main(String args[])
 {
  temp4 temp=new temp4(6.0,4.0);
 }
}
