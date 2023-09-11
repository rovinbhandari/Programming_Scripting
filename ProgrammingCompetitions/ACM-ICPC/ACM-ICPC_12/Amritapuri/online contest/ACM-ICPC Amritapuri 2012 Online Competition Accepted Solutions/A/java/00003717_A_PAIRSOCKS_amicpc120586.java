import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.*;

class A_PAIRSOCKS {

	/**
	 * @param args
	 */
	public static void main(String[] args)throws IOException {
		// TODO Auto-generated method stub

		BufferedReader input = new BufferedReader(new InputStreamReader(System.in));
		int t = Integer.parseInt(input.readLine());
		String res[] = new String[t];
		for(int i=0;i<t;i++)
		{
			String tmp = input.readLine();
			int arr[] = new int[4];
			for(int j=0;j<tmp.length();j++)
			{
				if(tmp.charAt(j)=='R')
					arr[0] = arr[0]+1;
				else if(tmp.charAt(j)=='G')
					arr[1] = arr[1]+1;
				else if(tmp.charAt(j)=='B')
					arr[2] = arr[2]+1;
				else
					arr[3] = arr[3]+1;
				
			}
			if(arr[0]%2==0 && arr[1]%2==0 && arr[2]%2==0 &&arr[3]%2==0)
				res[i]="YES";
			else
				res[i]="NO";
		}
		for(int i=0;i<t;i++)
			System.out.println(res[i]);
	}

}
