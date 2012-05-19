/*                  PROGRAM TO REVERT THE WORDS OF A STRING                 */
import java.io.*;
class twentytwo
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("");
  System.out.println(" PROGRAM TO REVERT THE WORDS OF A STRING ");
  System.out.println("*=======================================*");
  System.out.println("");
  System.out.println("ENTER A STRING OF WORDS :");
  String a = x.readLine();
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
  System.out.println("YOU HAVE ENTERED :" + d);
  System.out.println("");
  System.out.println("RESULT : " + b);
  System.out.println("");
}
}

