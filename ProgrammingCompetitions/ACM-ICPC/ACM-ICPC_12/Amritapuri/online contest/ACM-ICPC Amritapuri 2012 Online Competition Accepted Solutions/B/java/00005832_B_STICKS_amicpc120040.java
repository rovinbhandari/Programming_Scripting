//package template;
//TEMPLATE FOR NORMAL STANDARD INPUT OUTPUT
//TEMPLATE FOR FILE INPUT AND FILE OUTPUT
//NOTE: IT IS NOT FOR THE EOF KIND OF QUESTIONS
//package template;

import java.io.BufferedReader;
import java.io.PrintWriter;
import java.io.InputStreamReader;
import java.io.IOException;
import java.util.*;

public class Main implements Runnable{
        
    public static void main(String args[]){
       new Main().run();
    }
    
     public static final String INPUT_FILE = "input.in";
     public static final String OUTPUT_FILE = "output.out";
  
    @Override
    public void run(){
        try{
//        in = new BufferedReader(new FileReader(INPUT_FILE));
//        out = new PrintWriter(new BufferedWriter(new FileWriter(OUTPUT_FILE)));
            in = new BufferedReader(new InputStreamReader(System.in));
            out = new PrintWriter(System.out);
            tok = null;
            solve();
            in.close();
            out.close();
            
        }
        catch(IOException e){
            e.printStackTrace();
            System.exit(0);
        }
    }
    
    int nextInt()throws IOException{
        return Integer.parseInt(nextToken());
    } 
    
    double nextDouble()throws IOException{
        return Double.parseDouble(nextToken());
    }
    
    long nextLong() throws IOException{
        return Long.parseLong(nextToken());
    }
    
    String nextToken()throws IOException{
        while(tok == null || !tok.hasMoreTokens()){
            tok = new StringTokenizer(in.readLine());
        }
        return tok.nextToken();
    }
    
    BufferedReader in;
    PrintWriter out;
    StringTokenizer tok;
    //////////////////////////////////////////////////////////////////
    

    private void solve()throws IOException{
    	int T = nextInt();
    	while(T-- > 0) solve1();
    }//sovle
    
    private void solve1() throws IOException{
    	int N = nextInt();
    	int B = nextInt();
    	long[] arr = new long[N];
    	for(int i = 0; i < N; i++) arr[i] = nextInt();
    	
    	long max = 0;
    	for(int i = 0; i < B; i++){
    		long a = nextInt();
    		long b = nextInt();
    		long c = nextInt();
    		long now = a * a + b * b + c * c;
    		max = Math.max(max, now);
    	}
    	
    	int count = 0;
    	for(int i = 0; i < N; i++){
    		if(arr[i] * arr[i] <= max)count++;
    	}
    	
    	System.out.println(count);
    }
}