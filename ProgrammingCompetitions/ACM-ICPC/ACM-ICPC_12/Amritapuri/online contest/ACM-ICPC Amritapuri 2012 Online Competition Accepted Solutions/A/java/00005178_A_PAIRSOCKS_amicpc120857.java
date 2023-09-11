import java.io.*;
public class ProgA {
	
	public static void main(String args[]) throws NumberFormatException, IOException 
	{
	
		int i,j;
		boolean R,G,W,B;
		R=G=W=B=true;
		String s;
	
	/*try {
			System.setIn(new FileInputStream("E:\\GWT\\Project\\Code\\src\\in.txt"));
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
	*/
		BufferedReader k = new BufferedReader(new InputStreamReader(System.in));
		int test=Integer.parseInt(k.readLine());
		
		for (i=0;i<test;i++)
		{
			R=G=W=B=true;
			s=k.readLine();
			{
			for (j=0;j<s.length();j++)
			{
				switch(s.charAt(j))
				{
				case 'R':R=!R;
				break;
				case 'G':G=!G;
				break;
				case 'W':W=!W;
				break;
				case 'B':B=!B;
				}
			}
			
			if(R && G && B && W)
				System.out.println("YES");
			else
				System.out.println("NO");
		}}
		
			}
}

