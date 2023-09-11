import java.io.*;
import java.util.*;
import java.net.*;
class Socks
{
public static void main(String args[])
{
String[] c=new String[10000];
int T;
Scanner n=new Scanner(System.in);
T=n.nextInt();		
for(int i=1;i<=T;i++)	
{
c[i]=n.next();

}
for(int m=1;m<=T;m++)
{
int r=0,w=0,b=0,g=0,l=0;
l=c[m].length();
char[] ch=new char[50];
ch=c[m].toCharArray();
for(int j=0;j<l;j++)
{

if(ch[j]=='R'||ch[j]=='W'||ch[j]=='G'||ch[j]=='B')
{
switch(ch[j])
{
case 'R':r++;break;
case 'W':w++;break;
case 'B':b++;break;
case 'G':g++;break;
}
}
}
if((r%2==0)&&(w%2==0)&&(b%2==0)&&(g%2==0))
System.out.println("YES");
else
System.out.println("NO");
}
}
}
	

