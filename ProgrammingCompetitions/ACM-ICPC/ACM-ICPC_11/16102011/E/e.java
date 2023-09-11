import java.io.*;
import java.math.*;
import java.lang.Math;

class e
{
	static int a[];
	static BigInteger b[];
	
	public static void main(String args[]) throws IOException
	{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		int t, n;
		t = Integer.parseInt(br.readLine());
		while(t-- > 0)
		{
			n = Integer.parseInt(br.readLine());
			a = new int[n + 1];
			b = new BigInteger[n + 1];
			for(int i = 1; i <= n; i++)
			{
				a[i] = Integer.parseInt(br.readLine());
			}
			b[0] = BigInteger.valueOf(1);
			int ai, z;
			BigInteger bi1;
			z = 0;
			for(int i = 1; i <= n; i++)
			{
				ai = a[i];
				bi1 = b[i - 1];
				while(ai < bi1.intValue())
				{
					bi1.multiply(BigInteger.valueOf(10));
					z++;
				}
				while(ai - (bi1.mod(BigInteger.valueOf(ai))).intValue() >= (int) Math.pow(10.0d, (double) z))
				{
					bi1.multiply(BigInteger.valueOf(10));
					z++;
				}
				b[i] = bi1.add(BigInteger.valueOf(ai - (bi1.mod(BigInteger.valueOf(ai))).intValue()));
			}
			System.out.println(b[n]);
		}
	}
}
