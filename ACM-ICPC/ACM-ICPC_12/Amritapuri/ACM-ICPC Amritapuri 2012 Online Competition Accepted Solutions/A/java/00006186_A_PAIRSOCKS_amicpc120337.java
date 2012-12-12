/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author swathi
 */
public class A_PAIRSOCKS {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
       
        int n,rc=0,gc=0,wc=0,bc=0,count=0;
        String inp[]=new String[1000];
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        do
        {
            //System.out.println("Enter a no of testcases:");
        n=Integer.parseInt(br.readLine());
        if((n<=1000)&&(n>=1)){
        //System.out.println("enter "+n+" no of strings with values R,G,B,W");
        for(int i=0;i<n;i++)
        {  
            inp[i]=br.readLine().toUpperCase();
            if(inp[i].length()>50){
                System.out.println("ReEnter the String:");
                inp[i]=br.readLine().toUpperCase();
            }
                
        }
        for(int i=0;i<n;i++)
            
        {   rc=gc=wc=bc=0;
            for(int j=0;j<inp[i].length();j++)
            {
                if(inp[i].charAt(j)=='R')
                    rc++;
                else if(inp[i].charAt(j)=='G')
                    gc++;
                 else if(inp[i].charAt(j)=='W')
                    wc++;
                 else if(inp[i].charAt(j)=='B')
                    bc++;
            }
           if((rc%2==0)&&(gc%2==0)&&(wc%2==0)&&(bc%2==0))  
               System.out.println("YES");
           else 
               System.out.println("NO");
           count++;
        }
        
        }
        else
        {
            System.out.println("No of test cases should be in the range of 1-1000");
            //goto test;
        }
        }while(count==0);
        
    }
}
