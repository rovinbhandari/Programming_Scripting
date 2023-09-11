import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.Stack;

/**
 * 
 */

/**
 * @author UMASHANKAR
 *
 */
public class pairSocks {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String c[];
		int T=0;
		String out="";
		BufferedReader br =new BufferedReader(new InputStreamReader(System.in));
		try {
			T=Integer.parseInt(br.readLine());
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		c=new String[T];
		Stack<Integer> R =new Stack<Integer>();
		Stack<Integer> G =new Stack<Integer>();
		Stack<Integer> B =new Stack<Integer>();
		Stack<Integer> W =new Stack<Integer>();
		for(int i=0;i<T;i++)
		{
			try {
				c[i]=br.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			char line[]=c[i].toCharArray();
			for(int j=0;j<c[i].length();j++)
			{
				if(line[j]=='R')
					R.push(1);
				if(line[j]=='G')
					G.push(1);
				if(line[j]=='B')
					B.push(1);
				if(line[j]=='W')
					W.push(1);

			}
			if(R.size()%2==0 && B.size()%2==0 && G.size()%2==0 && W.size()%2==0)
			{
				out+="YES\n";
			}
			else
				out+="NO\n";
			R.removeAllElements();
			G.removeAllElements();
			B.removeAllElements();
			W.removeAllElements();
		}
		System.out.print(out);
		// TODO Auto-generated method stub

	}

}
