/*Program to print all the even numbers from 84 to 100
  and to calculate their sum as well as product using
  do-while loop.
*/
class seven
{
 public static void main(String args[])
 {
  int sum=0;
  int pro=1;
  int i=84;
  do
  {
   sum=sum+i;
   pro=pro*i;
   System.out.println(i);
   i=i+2;
  }
  while (i<=100);
  System.out.println("Sum = "+sum);
  System.out.println("Pro = "+pro);
 }
}
