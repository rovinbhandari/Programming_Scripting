
import java.util.*;
import java.lang.*;
public class Main
{
public static void main (String args [])
{
Scanner sc=new Scanner (System.in);

int y=sc.nextInt ();


for (int t=0;t<y;t++)
{
int r=0,g=0,b=0,w=0; 
String x=sc.next ();
char a[]=x.toCharArray ();
for (int z=0;z<x.length ();z++)
{
if (a[z]=='R')r++;
if (a[z]=='G')g++;
if (a[z]=='B')b++;
if (a[z]=='W')w++;
}
if (r%2==0 && g%2==0 && b%2==0 && w%2==0)
System.out.println ("YES");
else
System.out.println ("NO");
}
}
}
