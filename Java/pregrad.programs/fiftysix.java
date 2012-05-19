/*   PROGRAM TO REVERSE A STRING CHARACTERWISE WITHOUT USING StringBuffer   */
import java.io.*;
class fiftysix
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x=new BufferedReader(new InputStreamReader(System.in));
  System.out.println("");
  System.out.println("Enter a string :");
  String a=x.readLine();
  String b="";
  int c=a.length();
  for(int i=(c-1);i>=0;i--)
  {
   b=b+a.charAt(i);
  }
  System.out.println(" ");
  System.out.println("Reversed (characterwise) string : ");
  System.out.println(b);
  System.out.println(" ");
  System.out.println(" ");
 }
}
