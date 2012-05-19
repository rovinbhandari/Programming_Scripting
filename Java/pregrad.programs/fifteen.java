import java.lang.*;
import java.io.*;
class fifteen
{
 public static void main(String args[]) throws IOException
 {
  InputStreamReader a = new InputStreamReader(System.in);
  BufferedReader x = new BufferedReader(a);
  System.out.println("Enter unicode of character :");
  String b = x.readLine();
  char c = Character.parseChar(b);
  System.out.println(c);
 }
}

