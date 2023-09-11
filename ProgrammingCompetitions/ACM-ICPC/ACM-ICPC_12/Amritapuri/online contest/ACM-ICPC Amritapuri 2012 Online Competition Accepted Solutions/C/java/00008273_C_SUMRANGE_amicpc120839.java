import java.util.*;
import java.math.*;
import java.io.*;

public class Main
	{
	public static void main(String args[]) throws IOException
		{
		BufferedReader c=new BufferedReader(new InputStreamReader(System.in));
		//Scanner c=new Scanner(System.in);
		int T=Integer.parseInt(c.readLine());
		for(int t=0;t<T;t++)
			{
			String S[]=c.readLine().split(" ");
			int N=Integer.parseInt(S[0]);
			int L=Integer.parseInt(S[1]);
			int H=Integer.parseInt(S[2]);
			int A[]=new int[N];
			StringTokenizer st=new StringTokenizer(c.readLine());
			for(int i=0;i<N;i++)
				A[i]=Integer.parseInt(st.nextToken());
			Arrays.sort(A);
			int ans=solve(A,H)-solve(A,L-1);
			System.out.println(ans/3);
			}
		}

	private static int solve(int [] A, int MAX)
		{
		int N=A.length;
		int ans=0;
		for(int i=0;i<N;i++)
			{
			for(int j=i+1;j<N;j++)
				{
				int sum=A[i]+A[j];
				int left=MAX-sum;
				int num=binarySearch(A,left);
				if(A[i]<=left)
					num--;
				if(A[j]<=left)
					num--;
				ans+=num;
				}
			}
		return ans;
		}

	private static int binarySearch(int [] A, int key)
		{
		int N=A.length;
		int lo=0;
		int hi=N-1;
		if(A[N-1]<=key)
			return N;
		if(A[0]>key)
			return 0;
		while(hi-lo>=5)
			{
			int mid=(hi+lo)/2;
			if(A[mid]>key)
				hi=mid+1;
			else
				lo=mid-1;
			}
		for(int i=lo;i<=hi;i++)
			{
			if(A[i]>key)
				return i;
			}
		return 0;
		}
	}

//must declare new classes here