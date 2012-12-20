import java.io.*;
import java.util.Scanner;
import java.lang.Math;

class Stic
{
public static void main(String[] args)throws Exception
{
int t,j,i,k,max,ml1,n,m;
long ml;
Scanner scan = new Scanner(System.in);
t=scan.nextInt();
int out[]=new int[t];
for(i=0;i<t;i++)
{
n=scan.nextInt();
m=scan.nextInt();
int s[]=new int[n];
int d[][]=new int[m][3];
for(j=0;j<n;j++)
s[j]=scan.nextInt();
d[0][0]=scan.nextInt();
d[0][1]=scan.nextInt();
d[0][2]=scan.nextInt();
ml=((long)(d[0][0]*d[0][0]))+((long)(d[0][1]*d[0][1]))+((long)(d[0][2]*d[0][2]));
max=(int)Math.sqrt(ml);
for(j=1;j<m;j++)
{
d[j][0]=scan.nextInt();
d[j][1]=scan.nextInt();
d[j][2]=scan.nextInt();
ml=(((long)(d[j][0]*d[j][0]))+((long)(d[j][1]*d[j][1]))+((long)(d[j][2]*d[j][2])));
ml1=(int)Math.sqrt(ml);
if(ml1>max)
max=ml1;
}
out[i]=0;
for(j=0;j<n;j++)
{
if(s[j]<=max)
out[i]++;
}
}

for(i=0;i<t;i++)
System.out.println(out[i]);
}
}