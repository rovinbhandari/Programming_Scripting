import java.util.StringTokenizer;
import java.io.BufferedReader;
import java.io.InputStreamReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.OutputStream;
import java.io.PrintWriter;
import java.math.*;

public class Main {
	public static void main(String args[])throws Exception{
		InputStream inputStream = System.in;
		OutputStream outputStream = System.out;
		InputReader in = new InputReader(inputStream);
		PrintWriter out = new PrintWriter(outputStream);
		int test=in.nextInt();
		while(test-->0){
			int n = in.nextInt();
			int m = in.nextInt();
			int[] arr = new int[100001];
			while(n-- > 0){
				int a;
				a = in.nextInt();
				arr[a]++;
			}
			int sum = arr[0];
	        for(int k = 1;k<100001;k++){
	              sum = sum + arr[k];
	              arr[k] = sum;
	        }
	        sum = 0;
	        long a,b,c;
	        a = in.nextLong();b = in.nextLong();c = in.nextLong();
	        long st = a*a + b*b + c*c;
	        String s = st+"";
	            //System.out.println("s is: "+s);
	            //BigInteger as = new BigInteger(s);
	            //BigSquareRoot app = new BigSquareRoot ();
	            //int length = s.length ();
	            //if (length > 20) {
	             // app.setScale (length / 2);
	           // }
	            int diag =(int) Math.sqrt(st);
	            //System.out.println("diag: "+diag);
	            if(diag > 100000) {sum = 100000;continue;}
	            sum = arr[diag];
	            m--;
	        while(m-- > 0){
	        	a = in.nextLong();b = in.nextLong();c = in.nextLong();
	        	st = a*a + b*b + c*c;
	        	//s = st + "";
	            //System.out.println("s is: "+s);
	            //as = new BigInteger(s);
	            //app = new BigSquareRoot ();
	            //length = s.length ();
	           // if (length > 20) {
	             // app.setScale (length / 2);
	            //}
	            diag =(int) Math.sqrt(st);
	            //System.out.println("diag: "+diag);
	            //printf("diag: %ld\n",diag);
	            if(diag > 100000) {/*printf("arr[100000]: %ld\n",arr[100000])*/;sum = sum>arr[100000]?sum:100000;continue;}
	            sum =sum>arr[diag]?sum:arr[diag];
	        }
	        System.out.println(sum);
		}
		
	}

}
class InputReader
{
    BufferedReader in;
    StringTokenizer tokenizer=null;
 
    public InputReader(InputStream inputStream)
    {
        in=new BufferedReader(new InputStreamReader(inputStream));
    }
    public String next()
    {
        try{
            while (tokenizer==null||!tokenizer.hasMoreTokens())
            {
                tokenizer=new StringTokenizer(in.readLine());
            }
            return tokenizer.nextToken();
        }
        catch (IOException e)
        {
            return null;
        }
    }
    public int nextInt()
    {
        return Integer.parseInt(next());
    }
    public long nextLong()
    {
        return Long.parseLong(next());
    }
}