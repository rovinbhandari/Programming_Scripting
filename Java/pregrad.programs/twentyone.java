/*               PROGRAM TO REVERT THE CHARACTERS OF A STRING               */
import java.io.*;
class twentyone
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("");
  System.out.println("PROGRAM TO REVERT THE CHARACTERS OF A STRING");
  System.out.println("============================================");
  System.out.println("");
  System.out.println("ENTER A STRING :");
  String s = x.readLine();
  String s1 = "";
  String s2 = " ";
  s = s + s2;
  String s3 = s;
  int a = 0;
  int b = 1;
  while(s.length() > 0)
  {
   s1 = s.substring(a,b) + s1;
   s = s.substring(1);
  }
  System.out.println("");
  System.out.println("");
  System.out.println("YOU HAVE ENTERED : " + s3);
  System.out.println("");
  System.out.println("RESULT :" + s1);
  System.out.println("");
  System.out.println("");
 }
}
