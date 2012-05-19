import java.io.*;
class temp6
{
 void palindrome() throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("ENTER A WORD :");
  String s = x.readLine();
  int l=s.length();
  String s1 = "";
  for(int i=l-1;i>=0;i--)
  s1=s1+s.charAt(i);
  if(s.equals(s1))
  System.out.println("PALINDROME");
  else
  System.out.println("NOT A PALINDROME");
 }
}
class t6
{
 public static void main(String args[]) throws IOException
 {
  temp6 t = new temp6();
  t.palindrome();
 }
}
