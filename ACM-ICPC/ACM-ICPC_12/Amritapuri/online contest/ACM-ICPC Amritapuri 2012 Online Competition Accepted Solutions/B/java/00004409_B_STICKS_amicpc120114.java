import java.io.*;
import java.util.*;
import java.lang.Math.*;
public class stick
{
     public static void main(String args[])throws Exception
     {
         BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
         PrintWriter pw = new PrintWriter(System.out);
         StringTokenizer st;
         int t=Integer.parseInt(br.readLine());
         int n,m,i,j,p,q,r,ctr;
         double k;
         String s;
         while(t>0)
         {
             ctr=0;
             t--;
             s=br.readLine();
             while(s.equals(""))
             {
             s=br.readLine();
             }
             st=new StringTokenizer(s);
             n=Integer.parseInt(st.nextToken());
             m=Integer.parseInt(st.nextToken());
             int a[]=new int[n];
             for(i=0;i<n;i++)
             {
                 a[i]=Integer.parseInt(br.readLine());
                }
             double b[]=new double[m];   
             for(i=0;i<m;i++)
             {
                 st=new StringTokenizer(br.readLine());
                  
                      p=Integer.parseInt(st.nextToken());
                      q=Integer.parseInt(st.nextToken());
                      r=Integer.parseInt(st.nextToken());
                      
                      b[i]=Math.sqrt((p*p+0.0)+(q*q+0.0)+(r*r+0.0));
                }
              k=b[0];  
             for(i=1;i<m;i++)
             {
                 k=Math.max(b[i],k);
                }
             for(i=0;i<n;i++)
             {
                 if((a[i]+0.0)<=k)
                 ctr++;
                }
              pw.println(ctr);  
            }
            pw.flush();
     }
}