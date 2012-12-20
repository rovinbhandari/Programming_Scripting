import java.io.*;
import java.util.*;

class Main
{
public static void main(String args[]) throws IOException
{
    BufferedReader in = new BufferedReader (new InputStreamReader (System.in));
    StringTokenizer token;
    char[] c = new char[50];
    String input;
    int R, G, B, W;
    int T, i;
    T = Integer.parseInt(in.readLine());
    while(T>0)
    {
         T--;
         i=0;
         R=G=B=W=0;
         input = in.readLine();
         for(i=0; i<input.length(); i++)
         {
             if(input.charAt(i)=='R')
                R++;
             else if(input.charAt(i)=='G')
                G++;
             else if(input.charAt(i)=='B')
                B++;
             else
                W++;
         }
         if(R%2==0 && G%2==0 && W%2==0 && B%2==0)
            System.out.println("YES");
         else
            System.out.println("NO");
            
    }
}
}