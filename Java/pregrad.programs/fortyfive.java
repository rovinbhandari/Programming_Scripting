/*                    PROGRAM TO FIND ARMSTRONG NUMBERS                     */
class fortyfive
{
 public static void main(String args[])
 {
  System.out.println("ARMSTRONG NUMBERS");
  int sum;
  for(int i = 0;i <= 10000 ;i++)
  {
   sum = 0;
   int a = i;
   while(a > 0)
   {
    int s = a % 10;
    sum = sum + ( s * s * s );
    a = a / 10;
   }
   if(sum==i)
   {
    System.out.println("==> " + i);
   }
  }
 }
}
