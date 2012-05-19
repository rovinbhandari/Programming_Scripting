/*                 PROGRAM TO PRINT THE  PASCAL's TRIANGLE                  */
import java.io.*;
class thirtythree
{
 public static void main(String args[]) throws IOException
 {
  System.out.println("");
  System.out.println("-------------------------------PASCAL's TRIANGLE--------------------------------");
  System.out.println("");
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter the number of lines to be printed :");
  int a = Integer.parseInt(x.readLine());
  int z[] = new int[a + 4];
  int i,j,k,l;
  for(i = 0;i < (a + 4);i++)
  {
   z[i] = 0;
  }
  z[1] = 1;
  j = 2;
  k = 0;
  System.out.println("");
  System.out.println(" 1");
  while(j <= a)
  {
   l = j;
   while(l > 0)
   {
    z[l] = (z[l] + z[l - 1]) % 10;
    l--;
   }
   j++;
   if(j > 3)
   {
    System.out.println(" ");
   }
   for(int m = 1;m < j;m++)
   {
    System.out.print(" " + z[m]);
   }
  }
  System.out.println("");
  System.out.println("--------------------------------------------------------------------------------");
 }
}

