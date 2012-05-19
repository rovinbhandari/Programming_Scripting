import java.lang.Math;
import java.io.*;
class l2p1a
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		double sinx, x, term;
		long fac, i, n, N;
		n = 1l;
		sinx = 0.0d;
		System.out.print("\n\n\tEnter the value of x in radians to calculate its sine : ");
		x = Double.parseDouble(br.readLine());
		System.out.print("\n\n\tEnter the value of the number of terms to compute\n\tin the expansinon of sin(x) : ");
		N = Long.parseLong(br.readLine());
		while(n <= N)
		{
			i = 2;
			fac = 1;
			while(i <= (2 * n - 1))
			{
				fac *= i;
				i++;
			}
			System.out.print("\n" + n + ").\t" + Math.pow(-1, (n + 1)) + " * " + Math.pow(x, (2 * n - 1)) + " / " + ((double) fac));
			sinx += Math.pow(-1, (n + 1)) * Math.pow(x, (2 * n - 1)) / ((double) fac);
			n++;
		}
		System.out.print("\n\n\tsin(" + x + ") (computed till " + N + " terms) = " + sinx + "\n\n");
	}
}
	
