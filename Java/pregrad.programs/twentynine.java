/*          PROGRAM TO REVERT THE CHARACTERS OF WORDS OF A STRING           */
import java.io.*;
class twentynine
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("");
  System.out.println("PROGRAM TO REVERT THE CHARACTERS OF WORDS OF A STRING");
  System.out.println("=====================================================");
  System.out.println("");
  System.out.println("ENTER A STRING :");
  String s = x.readLine();
  String s1 = "";
  String s2 = " ";
  s = s + s2;
  String s3 = s;
  int m = 0;
  int n = 1;
  while(s.length() > 0)
  {
   s1 = s.substring(m,n) + s1;
   s = s.substring(1);
  }
  String a = s1; 
  String b = "";
  String c = " ";
  a = a.trim();
  a = c + a;
  String d = a;
  while(a.indexOf(' ') > -1)
  {
   b = b + a.substring(a.lastIndexOf(' '));
   a = a.substring(0,a.lastIndexOf(' '));
  }
  System.out.println("");
  System.out.println("");
  System.out.println("YOU HAVE ENTERED : " + s3);
  System.out.println("");
  System.out.println("RESULT :" + b);
  System.out.println("");
  System.out.println("");
 }
}
