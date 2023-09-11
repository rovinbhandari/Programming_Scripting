import java.util.*;
import java.math.*;
import java.io.*;

public class Main
	{
	public static void main(String args[]) throws IOException
		{
		//BufferedReader c=new BufferedReader(new InputStreamReader(System.in));
		Scanner c=new Scanner(System.in);
		int T=c.nextInt();
		for(int t=0;t<T;t++)
			{
			int N=c.nextInt();
			int M=c.nextInt();
			long Len[]=new long[N];
			for(int i=0;i<N;i++)
				{
				long l=c.nextInt();
				Len[i]=l*l;
				}
			long maxDiag=0;
			for(int i=0;i<M;i++)
				{
				long a=c.nextInt();
				long b=c.nextInt();
				long c1=c.nextInt();
				maxDiag=Math.max(maxDiag,a*a+b*b+c1*c1);
				}
			int ans=0;
			for(int i=0;i<N;i++)
				{
				if(Len[i]<=maxDiag)
					ans++;
				}
			System.out.println(ans);
			}
		}
	}

//must declare new classes here