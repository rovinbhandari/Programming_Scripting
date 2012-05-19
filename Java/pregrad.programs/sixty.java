/*PROGRAM TO FIND THE AVERAGE OF INDEFINITE NUMBERS ENTERED IN A SINGLE LINE
                                  SEPARATED BY SPACE (USING StringTokenizer)*/
import java.io.*;
import java.util.*;
class sixty
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x=new BufferedReader(new InputStreamReader(System.in));
  System.out.println("");
  System.out.println("Enter the values (separated by a space) :");
  System.out.print("==> ");
  String a=x.readLine();
  StringTokenizer b=new StringTokenizer(a);
  int c=b.countTokens();
  String d;
  double e,f;
  f=0.0d;
  for(int i=0;i<c;i++)
  {
   d=b.nextToken();
   e=Double.parseDouble(d);
   f=f+e;
  }
  double avg=f/(double)c;
  System.out.println("");
  System.out.println("Average of the numbers entered = "+avg);
  System.out.println("");
 }
}
