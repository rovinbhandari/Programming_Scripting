//Program to add two numbers by parameter passing through functions
class five
{
 void display(int a,int b)
 {
  int c=a+b;
  System.out.println("1st no.:"+a);
  System.out.println("2nd no.:"+b);
  System.out.println("Sum = "+c);
 }
}
class five1
{
 public static void main(String args[])
 {
  five f1=new five();
  f1.display(84,126);
 }
}
