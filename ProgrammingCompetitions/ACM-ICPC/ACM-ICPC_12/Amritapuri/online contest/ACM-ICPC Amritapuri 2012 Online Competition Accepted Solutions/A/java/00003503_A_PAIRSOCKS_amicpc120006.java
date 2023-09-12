/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */
//package main;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

/**
 *
 * @author 09it14
 */
class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException {
        // TODO code application logic here
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int n=Integer.parseInt(br.readLine());
        int i=0;
        while(n--!=0){
        String sr=br.readLine();
        int[] a=new int[200];
        for(i=0;i<sr.length();i++)
            a[sr.charAt(i)]=0;
        
        for( i=0;i<sr.length();i++){
        char ad=sr.charAt(i);
        a[ad]=a[ad]+1;
      //  System.out.println(a[ad]+" "+ad);
        }
        for( i=0;i<sr.length();i++)
            if(a[sr.charAt(i)]%2!=0)
                break;
        
        if(i==sr.length())
            System.out.println("YES");
        else
            System.out.println("NO");
            
        }
        
    }
}
