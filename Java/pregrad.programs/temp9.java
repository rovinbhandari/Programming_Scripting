import java.io.*;
class temp9
{
 public static void main(String args[]) throws IOException
 {
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter a String : ");
  String s =x.readLine();
  s=s.trim();
  char ch;
  int a,e,i,o,u;
  a=e=i=o=u=0;
  for(int t=0;t<s.length();t++)
  {
   ch=s.charAt(t);
   switch(ch)
   {
    case 'a' :
    case 'A' : a++;
               break;
    case 'e' :
    case 'E' : e++;
               break;
    case 'i' :
    case 'I' : i++;
               break;
    case 'o' :
    case 'O' : o++;
               break;
    case 'u' :
    case 'U' : u++;
               break;
   }
  }
  System.out.println("A/a : "+a); 
  System.out.println("E/e : "+e);
  System.out.println("I/i : "+i);
  System.out.println("O/o : "+o);
  System.out.println("U/u : "+u);
 }
}
