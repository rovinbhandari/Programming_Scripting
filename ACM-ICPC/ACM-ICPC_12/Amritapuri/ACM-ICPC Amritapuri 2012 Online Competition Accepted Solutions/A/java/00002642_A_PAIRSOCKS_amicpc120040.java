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
    	String s = nextToken();
    	int r = 0, g = 0, b = 0, w = 0;
    	for(char c : s.toCharArray()) {
    		if(c == 'R')r++;
    		else if(c == 'G')g++;
    		else if(c == 'B')b++;
    		else w++;
    	}
    	if(r % 2 == 0 && b % 2 ==0 && g % 2 ==0 && w % 2 ==0) System.out.println("YES");
    	else System.out.println("NO");
    }
}