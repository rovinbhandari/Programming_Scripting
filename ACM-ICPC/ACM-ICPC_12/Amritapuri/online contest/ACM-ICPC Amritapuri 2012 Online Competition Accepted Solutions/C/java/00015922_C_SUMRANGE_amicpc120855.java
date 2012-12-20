import java.util.*;
import java.math.*;
import java.io.*;

public class SumRange {
	public static void main(String args[]) throws IOException {
		
		Scanner c = new Scanner(System.in);
		
		int T = c.nextInt();
		for (int t = 0; t < T; t++) {
			int N = c.nextInt();
			long L = c.nextLong();
			long H = c.nextLong();
			
			long a[] = new long[N];
			
			for (int i = 0; i < N; i++) {
				a[i] = c.nextLong();
			}
			
			long A[][] = new long[N][N];

			for (int i = 0; i < N; i++) {
				for (int j = i+1; j < N; j++) {
						A[i][j]=a[i]+a[j];
				}
			}
			long b[] = new long[N];
			b=Arrays.copyOf(a, N);
			Arrays.sort(a);	
			
			float c1[]=new float[N];
			for(int i=0;i<N;i++) {
				c1[i]=(float)a[i];
			}
			long count=0;
			for (int i = 0; i < N; i++) {
				for (int j = i+1; j < N; j++) {
					float key = (float) ((float)(L-A[i][j])-0.5);
						int i1 = Arrays.binarySearch(c1, key);
						if(i1<0){
							i1=-i1-1;
						}
						
						key = (float) ((float)(H-A[i][j])+0.5);
						int i2 = Arrays.binarySearch(c1, key);
						if(i2<0){
							i2=-i2-2;
						}
						//System.out.println(A[i][j]);
						//System.out.println("key i1 i2 "+key+" "+i1+" "+i2);
						//i2--;
						if(i2>=i1){
							count+=(i2-i1+1);
						}
						//System.out.println(count);
				}
			}
			for (int i = 0; i < N; i++) {
				for (int j = i+1; j < N; j++) {
					if(A[i][j]+b[i]>=L && A[i][j]+b[i]<=H) {
						count--;
					}
					if(A[i][j]+b[j]>=L && A[i][j]+b[j]<=H) {
						count--;
					}
				}
			}
			count = count/3;
			System.out.println(count);

		}
	}
}