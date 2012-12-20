import java.io.*;

class Main
{
	public static void main(String args[]) throws Exception
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter out = new PrintWriter(new BufferedWriter(new OutputStreamWriter(System.out)));
		
		int t = Integer.parseInt(in.readLine());
		String alpha="RGBW";
		
		while(t-- > 0)
		{
			String str = in.readLine();
			int len = str.length();
			boolean count[] = new boolean[4];
			
			for(int i=0; i<len; i++)
			{
				count[alpha.indexOf(str.charAt(i))]=!count[alpha.indexOf(str.charAt(i))];
			}
			
			boolean done = false;
			for(int i=0; i<4; i++)
			{
				if(count[i])
				{
					done = true;
					out.println("NO");
					break;
				}
			}
			if(!done)
			{
				out.println("YES");
			}
		}	
		out.flush();
	}
}
