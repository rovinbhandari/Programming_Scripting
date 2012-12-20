import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class socks {

	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		BufferedReader keyin = new BufferedReader(new InputStreamReader(System.in));
		//int t;
		String str;
		int t=Integer.parseInt(keyin.readLine()); //int ch=1;
		for(int i=0;i<t;i++)
		{
			str=keyin.readLine();
			//int ch=str.charAt(0);
			int r=0,w=0,g=0,b=0; boolean err=false;
			for(int j=0;j<str.length();j++)
				{
				//ch=(ch ^ str.charAt(j));
				char ch=str.charAt(j);
				switch(ch)
				{
				case 'R': r++; break;
				case 'W': w++;break;
				case 'G': g++;break;
				case 'B': b++;break;
				default: err=true;
				}
				}
			if((r%2==0) && (w%2==0) && (g%2==0) && (b%2==0) && (str.length()<=50) && (!err)) System.out.println("YES");
			else System.out.println("NO");
		}
		
	}

}
