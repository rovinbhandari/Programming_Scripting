import java.io.*;
class temp7
{
 public static void main(String args[]) throws IOException
 {
  String country[] = {"India","China","Japan","Russia","SriLanka","Canada"};
  String capital[] = {"New Delhi","Beijing","Tokyo","Moscow","Colombo","Ottawa"};
  BufferedReader x = new BufferedReader(new InputStreamReader(System.in));
  System.out.println("Enter country :");
  String a = x.readLine();
  for(int i = 0;i<=6;i++)
  {
   if(i==6)
   System.out.println("Country not found");
   else
   {
    if(a.equalsIgnoreCase(country[i]))
    {
     System.out.println("Capitol city is : "+capital[i]);
     return;
    }
   }
  }
 }
}
