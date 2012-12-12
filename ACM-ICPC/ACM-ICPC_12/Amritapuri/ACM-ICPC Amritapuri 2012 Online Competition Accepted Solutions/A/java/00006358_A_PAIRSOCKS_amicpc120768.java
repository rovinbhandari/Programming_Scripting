import java.io.IOException;
import java.util.StringTokenizer;


public class socks {
	public static void main(String[] args) throws IOException {
		java.io.BufferedReader r = new java.io.BufferedReader
		(new java.io.InputStreamReader (System.in));
		StringTokenizer st = new StringTokenizer(r.readLine());
		int t = Integer.parseInt(st.nextToken());
		StringBuilder output = new StringBuilder();
		for(int i = 0 ; i < t ; i++)
		{
			st = new StringTokenizer(r.readLine());
			String str = st.nextToken();
			int len = str.length();
			int[] socks = new int[4];
			for(int k = 0 ; k < len ; k++)
			{
				char c = str.charAt(k);
				if(c == 'R')
					socks[0]++;
				if(c == 'G')
					socks[1]++;
				if(c == 'B')
					socks[2]++;
				if(c == 'W')
					socks[3]++;
				
			}
			boolean possible = true;
			for(int p=0;p<4;p++)
			{
				if((socks[p] & 1) == 1)
					possible = false;
			}
		
			if(possible)
				System.out.println("YES");
			else
				System.out.println("NO");
			
		}
		
		
	}

}
