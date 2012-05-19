/*     PROGRAM TO REVERSE A STRING WORDWISE WITHOUT USING StringBuffer      */
import java.io.*;
class fiftyseven
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("");
  System.out.println("Enter a string :");
  String a = x.readLine();
  String b = "";
  a = a.trim();
  int c = a.length();
  while(c>0)
  {
   a = " " + a;
   int d = a.lastIndexOf(' ');
   b = b + a.substring(d);
   a = a.substring(0,d);
   a = a.trim();
   c = a.length();
  }
  b = b.trim();
  System.out.println(" ");
  System.out.println("Reversed (wordwise) string : ");
  System.out.println(b);
  System.out.println(" ");
  System.out.println(" ");
 }
}
