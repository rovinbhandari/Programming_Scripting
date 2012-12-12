

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import java.util.Arrays;
import java.util.StringTokenizer;

public class Main
{

	public static void main(String[] args) throws IOException
	{
		FR2.init(System.in);
		int t = FR2.nextInt();
		while(t-- > 0)
		{
			int n = FR2.nextInt();
			int m = FR2.nextInt();
			
			int[] l = new int[n];
			for(int i = 0; i < n; i++)
			{
				l[i] = FR2.nextInt();
			}
			
			long a ;
			long b ;
			long c;
			long max ;
			
			long maxcap = Integer.MIN_VALUE;
			for(int i = 0; i < m; i++)
			{
				a = FR2.nextInt();
				b = FR2.nextInt();
				c = FR2.nextInt();
				max = (long) Math.floor( Math.sqrt(a * a + b * b+ c * c));
				if(max > maxcap)
				{
					maxcap = max;
				}
			}
			
			Arrays.sort(l);
			//System.out.println("max = " + maxcap);
			//for( int j = 0; j < n; j++) System.out.print(l[j] + " ");
			boolean done = false;
			for( int j = 0; j < n; j++)
			{
				if(l[j] > maxcap)
				{
					System.out.println(j);
					done = true;
					break;
				}
			}
			if(!done)
			{
				System.out.println(n);
			}
			
		}
	}

}
class FR2
{
	static BufferedReader reader;
	static StringTokenizer tokenizer;

	/** call this method to initialize reader for InputStream */
	static void init(InputStream input)
	{
		reader = new BufferedReader(new InputStreamReader(input));
		tokenizer = new StringTokenizer("");
	}

	/** get next word */
	static String next() throws IOException
	{
		while (!tokenizer.hasMoreTokens())
		{
			// TODO add check for eof if necessary
			tokenizer = new StringTokenizer(reader.readLine());
		}
		return tokenizer.nextToken();
	}

	static int nextInt() throws IOException
	{
		return Integer.parseInt(next());
	}

	static double nextDouble() throws IOException
	{
		return Double.parseDouble(next());
	}
}