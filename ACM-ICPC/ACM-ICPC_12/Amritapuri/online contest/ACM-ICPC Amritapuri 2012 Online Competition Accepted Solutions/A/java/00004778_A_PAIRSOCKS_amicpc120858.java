
import java.io.*;
import java.io.InputStreamReader;

/*
 * To change this template, choose Tools | Templates
 * and open the template in the editor.
 */

/**
 *
 * @author parth
 */
public class NewClass {
 int x[]=new int[4];
 String check(String a)
 {
     for(int k=0;k<4;k++)
         x[k]=0;
     for(int i=0;i<a.length();i++)
     {
         if(a.charAt(i)=='R')
         {
             x[0]++;
             
         }
         if(a.charAt(i)=='G')
         {
             x[1]++;
             
         }
         if(a.charAt(i)=='B')
         {
             x[2]++;
             
         }
         if(a.charAt(i)=='W')
         {
             x[3]++;
             
         }
     }
     for(int s=0;s<4;s++)
     {
         if(x[s]%2!=0)
             return"NO";
     }
     return "YES";
 }
    public static void main(String[] args)throws IOException {
        BufferedReader in=new BufferedReader(new InputStreamReader(System.in));
        int n;
        n=Integer.parseInt(in.readLine());
        String k[]=new String[n];
        for(int i=0;i<n;i++)
            k[i]=in.readLine();
        NewClass d=new NewClass();
        for(int i=0;i<n;i++)
            System.out.println(d.check(k[i]));
    }
}