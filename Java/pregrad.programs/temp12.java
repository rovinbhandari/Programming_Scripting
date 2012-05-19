import java.io.*;
class temp12
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  int z[] = new int[15];
  System.out.println("Enter the elements of array :");
  for(int i = 0;i < 15;i++)
  {
    z[i] = Integer.parseInt(x.readLine());
  }
  for(int i = 0;i < (15-1);i++)
  {
   for(int j = 0;j < (15 - 1);j++)
   {
    if(z[j+1] > z[j])
    {
     int c = z[j];
     z[j] = z[j + 1];
     z[j + 1] = c;
    }
   }
  }
  System.out.println("Descending order of the elements entered :");
  for(int i = 0;i < 15;i++)
  {
   System.out.println(z[i]);
  }
 }
}   
