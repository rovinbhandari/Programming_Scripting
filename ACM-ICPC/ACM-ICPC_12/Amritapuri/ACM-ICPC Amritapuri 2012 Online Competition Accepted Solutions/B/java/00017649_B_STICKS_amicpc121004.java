import java.io.*;
import java.math.BigInteger;


public class Main 
{
	
	public static void main(String[] args) throws IOException
	{
		BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
		String test = new String();
		test = in.readLine();
		int t, n, m;
		String[] dim = new String[3];
		String[] arg = new String[2];
		t = Integer.parseInt(test);
		for(int i=0; i<t; i++)
		{
			arg = in.readLine().split(" ");
			n = Integer.parseInt(arg[0]);
			m = Integer.parseInt(arg[1]);
			long[] lengths = new long[n];
			for (int j=0; j<n; j++)
			{
				lengths[j] =Integer.parseInt(in.readLine());
				lengths[j]=lengths[j]*lengths[j];
			}
			int l;
			int b;
			int h;
			long lr,br,hr;
			lr=hr=br=0;
			BigInteger max = new BigInteger("0");
			for(int j=0; j<m; j++)
			{
				dim = in.readLine().split(" ");
				l = Integer.parseInt(dim[0]);
				b = Integer.parseInt(dim[1]);
				h = Integer.parseInt(dim[2]);
				BigInteger vol=new BigInteger(l+"");
				vol=vol.multiply(new BigInteger(b+""));
				vol=vol.multiply(new BigInteger(h+""));
				if(vol.compareTo(max)>0)
				{
					max = vol;
					lr=l;
					br=b;
					hr=h;
				}
			}
			//System.out.println("max " + max);
			int count = 0;
			long num;
			for(int j=0; j<n; j++)
			{
				num=(lr*lr)+(br*br)+(hr*hr);
				if((long)lengths[j] <= num)
				{
					count = count+1;
				}
			}
			System.out.println(count);
			if(i!=(t-1))
				in.readLine();
		}
		
	}

}
