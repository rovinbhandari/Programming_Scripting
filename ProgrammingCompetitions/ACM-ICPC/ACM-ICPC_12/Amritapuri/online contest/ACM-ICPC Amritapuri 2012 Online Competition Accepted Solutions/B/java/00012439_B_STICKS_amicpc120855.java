import java.util.*;
import java.math.*;
import java.io.*;

public class Sticks {
	public static void main(String args[]) throws IOException {
		//BufferedReader c=new BufferedReader(new InputStreamReader(System.in));
		Scanner c = new Scanner(System.in);
		//int T=Integer.parseInt(c.readLine());
		int T = c.nextInt();
		for (int t = 0; t < T; t++) {
			int N = c.nextInt();
			int M = c.nextInt();
			long L[] = new long[N];
			//int Box[][] = new int[M][3];
			for(int i=0;i<N;i++) {
				L[i]=c.nextLong();
			}
			long max_diag=0;
			for (int i = 0; i < M; i++) {
				long A = c.nextLong();
				long B = c.nextLong();
				long C = c.nextLong();
				
				long len = A*A+B*B+C*C;
				if(len>max_diag){
					max_diag=len;
				}
			}
			int res=0;
			for (int i = 0; i < N; i++) {
				if(L[i]*L[i]<=max_diag){
					res++;
				}
			}
			System.out.println(res);

		}
	}
}