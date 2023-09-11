import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


public class Main {

	/**
	 * @param args
	 * @throws IOException 
	 * @throws NumberFormatException 
	 */
	public static void main(String[] args) throws NumberFormatException, IOException {
		// TODO Auto-generated method stub
		BufferedReader reader = new BufferedReader(new InputStreamReader(System.in));
		int noCases = Integer.parseInt(reader.readLine());
		for(int i=0; i<noCases; i++)
		{
			int R=0, G=0, B=0, W=0;
			String[] Colors = reader.readLine().split("");
			for(String z: Colors)
			{
				if(z.equals("R")) R++;
				if(z.equals("G")) G++;
				if(z.equals("B")) B++;
				if(z.equals("W")) W++;
			}
			if(R%2==0 && G%2==0 && B%2==0 && W%2==0)
				System.out.println("YES");
			else
				System.out.println("NO");
		}
	}

}
