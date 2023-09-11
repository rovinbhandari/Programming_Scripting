
import java.util.*;
import java.lang.*;
public class Main
{
static long ans=1;

public static void main (String args [])
{
Scanner sc=new Scanner (System.in);

int y=sc.nextInt ();
//System.out.println (Math.pow (y,2));
for (int t=0;t<y;t++)
{
long MAX=0;
int count=0;
int n=sc.nextInt ();
long L[]=new long [n];
int m=sc.nextInt ();
long A[]=new long [m];
long B[]=new long [m];
long C[]=new long [m];
long d[]=new long [m];
for (int i=0;i<n;i++)
{
L[i]=sc.nextLong ();
}

for (int j=0;j<m;j++)
{
A[j]=sc.nextLong ();
B[j]=sc.nextLong ();
C[j]=sc.nextLong ();
d[j]=(long)(Math.pow (A[j],2)+Math.pow(B[j],2)+Math.pow(C[j],2));

if (d[j]>=MAX)
MAX=d[j];
}
//System.out.println (MAX);
for (int k=0;k<n;k++)
{
if ((Math.pow(L[k],2))<=MAX){count++;
}
}

System.out.println (count);

}

}


}
