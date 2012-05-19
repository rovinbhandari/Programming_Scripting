/*       PROGRAM TO COUNT THE NUMBER OF WORDS IN A STRING              
                                    (WITHOPUT USING StringTokenizer)        */
import java.io.*;
class fiftyfive
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x=new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter a string :");
  String a=x.readLine();
  a=a.trim();
  int b=1;
  int c=a.length();
  int d=0;
  while((c>0)&&(d<c))
  {
   if(a.charAt(d)==' ')
   {
    b++;
    a=a.substring(d);
    a=a.trim();
    d=-1;
    c=a.length();
   }
   d++;
  }
  System.out.println("Number of words in the string entered = "+b);
 }
}

