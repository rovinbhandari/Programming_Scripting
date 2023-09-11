import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintWriter;

public class Socks {

	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		PrintWriter pw=new PrintWriter(System.out);
		int test =Integer.parseInt(br.readLine());
		for (int f = 0; f < test; f++) 
		{
			String socks=br.readLine();
			char socks_arr[]=socks.toCharArray();
			int red=0,green=0,white=0,blue=0;
			for(int i=0;i<socks_arr.length;i++)
			{
				if(socks_arr[i]=='B')
					blue++;
				else if(socks_arr[i]=='G')
					green++;
				else if(socks_arr[i]=='W')
					white++;
				else if(socks_arr[i]=='R')
					red++;
			}
			if(((blue%2)==0)&&((green%2)==0)&&((white%2)==0)&&((red%2)==0))
				pw.println("YES");
			else
				pw.println("NO");
		}
		pw.flush();
		}
	}


