
import java.io.*;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author akash09057
 */
class Ques1 {
    
    	public static boolean checkString(String str)
	{	
		boolean flag=true;
		int i;
		int[] arr = new int[4];
		
		for (i=0;i<str.length();i++)
		{
			switch (str.charAt(i))
			{
				case 'R':
					arr[0]++;
					break;
				case 'G':
					arr[1]++;
					break;
				case 'B':
					arr[2]++;
					break;
				case 'W':
					arr[3]++;
					break;
				default:
					break;	
			}
		}
		
		for (i=0;i<4;i++)
		{
			if (arr[i]%2==1)
			{
				flag=false;
				break;
			}
		}
		
		return flag;
	}
	
	/**
	 * @param args
	 * @throws IOException 
	 */
	public static void main(String[] args) throws IOException {
		// TODO Auto-generated method stub
		
		String str;
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int i,T;
		boolean flag;
		
		str = reader.readLine();
		
		T = Integer.parseInt(str);
		
		for (i=0;i<T;i++)
		{
			str = reader.readLine();
			flag = checkString(str);
			
			if (flag)
			{
				System.out.println("YES");
			}
			else
			{
				System.out.println("NO");
			}
		}
	}
    
}
