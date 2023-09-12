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
public class Sock {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		String C[];
		int T=0;
		String out="";
		BufferedReader BR =new BufferedReader(new InputStreamReader(System.in));
		try {
			T=Integer.parseInt(BR.readLine());
		} catch (NumberFormatException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		} catch (IOException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
		C=new String[T];
		Stack<Integer> RED =new Stack<Integer>();
		Stack<Integer> Green =new Stack<Integer>();
		Stack<Integer> Blue =new Stack<Integer>();
		Stack<Integer> White =new Stack<Integer>();
		for(int i=0;i<T;i++)
		{
			try {
				C[i]=BR.readLine();
			} catch (IOException e) {
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
			char line[]=C[i].toCharArray();
			for(int j=0;j<C[i].length();j++)
			{
				if(line[j]=='R')
					RED.push(1);
				if(line[j]=='G')
					Green.push(1);
				if(line[j]=='B')
					Blue.push(1);
				if(line[j]=='W')
					White.push(1);

			}
			if(RED.size()%2==0 && Blue.size()%2==0 && Green.size()%2==0 && White.size()%2==0)
			{
				out+="YES\n";
			}
			else
				out+="NO\n";
			RED.removeAllElements();
			Green.removeAllElements();
			Blue.removeAllElements();
			White.removeAllElements();
		}
		System.out.print(out);
		// TODO Auto-generated method stub

	}

}
