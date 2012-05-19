/*     PROGRAM TO REVERSE A STRING CHARACTERWISE AND WORDWISE
                                          (WITHOUT USING StringBuffer)      */
import java.io.*;
class fiftyeight
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("");
  System.out.println("Enter a string :");
  String n = x.readLine();
  String m = "";
  for(int i=(n.length()-1);i>=0;i--)
  {
   m=m+n.charAt(i);
  }
  String a=m;
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
  System.out.println("Reversed (characterwise and wordwise) string : ");
  System.out.println(b);
  System.out.println(" ");
  System.out.println(" ");
 }
}
