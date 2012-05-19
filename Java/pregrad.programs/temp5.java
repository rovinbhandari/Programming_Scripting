import java.io.*;
class temp5
{
 public static void main(String args[]) throws IOException
 {
  int s=1;
  float sum=0.0f;
  BufferedReader x =new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter n:");
  int n=Integer.parseInt(x.readLine());
  for(int i =2;i<=n;i++)
  {
   s=s+i;
   sum=sum+1/(float)s;
  }
  System.out.println(sum);
 }
}
