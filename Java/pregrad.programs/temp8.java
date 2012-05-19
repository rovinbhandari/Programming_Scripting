import java.io.*;
class temp8
{
 public static void main (String args[]) throws IOException
 {
  BufferedReader x=new BufferedReader(new InputStreamReader(System.in));
  int n[][]=new int[5][5];
  System.out.println("enter elements of array :");
  for(int i=0;i<5;i++)
  {
   System.out.println("for row "+(i+1));
   for(int j=0;j<5;j++)
   {
    n[i][j]=Integer.parseInt(x.readLine());
   }
  }
  boolean b1,b2;
  b1=b2=false;
  for(int i=0;i<5;i++)
  {
   for(int j=0;j<5;j++)
   {
    if(i==j)
    {
     if(n[i][j]==1)
     {
      b1=true;
     }
    }
    else if(n[i][j]==0)
    {
     b2=true;
    }
   }
  }
  if(b1==true && b2==true)
  System.out.println("Identity Matrix");
  else
  System.out.println("Not an Identity Matrix");
 }
}
