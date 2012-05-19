/*                  PROGRAM TO CALCULATE AGE OF A PERSON                   */
import java.io.*;
class eight
{
 public static void main(String args[]) throws IOException
 {
  System.out.println(" ");
  System.out.println(" ");
  System.out.println("<<<<<<<<<<<PROGRAM TO CALCULATE AGE OF A PERSON>>>>>>>>>>>");
  System.out.println("==========================================================");
  System.out.println(" ");
  InputStreamReader isr = new InputStreamReader(System.in);
  BufferedReader x = new BufferedReader(isr);
  System.out.println("Please enter your name : ");
  String n = x.readLine();
  System.out.println(" ");
  System.out.println("Enter current date : ");
  int d1 = Integer.parseInt(x.readLine());
  System.out.println(" ");
  System.out.println("Enter current month : ");
  String m11 = x.readLine();
  int m1 = Integer.parseInt(m11);
  System.out.println(" ");
  System.out.println("Enter current year : ");
  int y1 = Integer.parseInt(x.readLine());
  System.out.println(" ");
  System.out.println("Enter the date you were born : ");
  int d2 = Integer.parseInt(x.readLine());
  System.out.println(" ");
  System.out.println("Enter the month you were born : ");
  int m2 = Integer.parseInt(x.readLine());
  System.out.println(" ");
  System.out.println("Enter the year you were born : ");
  int y2 = Integer.parseInt(x.readLine());
  long a1 = (365*y1)+(30*m1)+d1;
  long a2 = (365*y2)+(30*m2)+d2;
  long a3 = a1-a2;
  int a4 = (int) a3/365;
  int a5 = (int) a3%365;
  int a6 = a5/30;
  int a7 = a5%30;
  System.out.println(" ");
  System.out.println(n+", YOUR AGE IS :");
  System.out.println(a4+" YEARS , "+a6+" MONTHS , "+a7+" DAYS");
  System.out.println(" ");
  System.out.println("===========================================================");
  System.out.println(" ");
 }
}
