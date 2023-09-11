import java.io.*;
public class pair
{
public static void main(String args[])throws Exception 
{
abc a=new abc();
a.socks();
}
}
class abc
{
void socks() throws Exception
{
String p[];
BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
int a[];
int i,j,n;
	n=Integer.parseInt(br.readLine());
	if(n<1 || n>1000)
		System.exit(0);
	a=new int[n];
	p=new String[n];
	for(i=0;i<n;i++)
	{
		p[i]=br.readLine();

	}
for(i=0;i<n;i++)
a[i]=check(p[i]);
for(i=0;i<n;i++)
{
if(a[i]==0)

System.out.println("YES");
else
System.out.println("NO");

}
}
int check(String k1)
{
char s[]=k1.toCharArray();
 int a[]={0,0,0,0};
int i,j,k=0;char temp;
for(j=0;j<s.length;j++)
{
  switch(s[j])
  {
  case 'R':
  a[0]++;
  break;
  case 'B':
  a[1]++;
  break;
  case 'G':
  a[2]++;
  break;
 case 'W':
 a[3]++;
 break;
 default:
 k=1;
break;
}
}
if(k==0)
{
for(i=0;i<4;i++)
{
 if((a[i]%2)==1)
 k=1;
}
}
return k;
}
}
