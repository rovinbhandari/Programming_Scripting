/*Program to check the greatest of three numbers*/
class two
{
 public static void main(String args[])
 {
  int a,b,c;
  a=12;
  b=45;
  c=23;
  System.out.println("a = "+a);
  System.out.println("b = "+b);
  System.out.println("c = "+c);
  System.out.println("-----------------------------------------------------");
  System.out.println();
  if(a>b && a>c)
  {
   System.out.println("a is the greatest number");
  }
  else if(b>c && b>a)
  {
   System.out.println("b is the greatest number");
  }
  else
  {
   System.out.println("c is the greatest number");
  }
 System.out.println("-----------------------------------------------------");
 }
}
