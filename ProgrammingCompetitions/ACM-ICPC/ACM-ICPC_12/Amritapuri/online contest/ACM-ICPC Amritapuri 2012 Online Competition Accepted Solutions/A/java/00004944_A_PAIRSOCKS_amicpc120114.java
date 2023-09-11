import java.io.*;
import java.util.*;
import java.lang.Math.*;
public class Icpc_1
{
     public static void main(String args[])throws Exception
     {
         //Scanner in=new Scanner(System.in);
         BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
         PrintWriter pw = new PrintWriter(System.out);
         StringTokenizer st;
         int t,r=0,b=0,g=0,w=0,i,j,k;
         t=Integer.parseInt(br.readLine());
         while(t>0)
         {
             r=0;g=0;w=0;b=0;
             t--;
             String s=br.readLine();
             int l=s.length();
             for(i=0;i<l;i++)
             {
                 char ch=s.charAt(i);
                 if(ch=='W')
                 w++;
                 else if(ch=='R')
                 r++;
                 else if(ch=='B')
                 b++;
                 else if(ch=='G')
                 g++;
             }
             if(g%2==0 && w%2==0 && r%2==0 && b%2==0)
             pw.println("YES");
             else
             pw.println("NO");
            }
            pw.flush();
        }
}