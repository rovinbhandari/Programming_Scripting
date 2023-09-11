//prblema


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main {

	
	public static void main(String[] args) throws NumberFormatException, IOException {
		int tcase,i,arr[],length;
		boolean flag;
		char a;
		String input;
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		tcase = Integer.parseInt(br.readLine());
		
		while(tcase!=0)
		{
			arr= new int [4];
			flag = false;
			input = br.readLine();
			length = input.length();
			for(i=0;i<length;i++)
			{
				a = input.charAt(i);
				if(a=='R')
				{
					arr[0]++;
				}
				else if(a=='G')
				{
					arr[1]++;
				}
				else if(a=='B')
				{
					arr[2]++;
				}
				else if(a=='W')
				{
					arr[3]++;
				}
				
					
			}
			for(i=0;i<4;i++)
			{
				//System.out.println("array val" + arr[i]);
				if(arr[i]%2 !=0 )
					flag =true;
			}
			
			if(flag == true)
				System.out.println("NO");
			else
				System.out.println("YES");
			tcase--;
		}

	}

}
