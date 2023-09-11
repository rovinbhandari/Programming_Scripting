import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;

public class Main{
     public static void main(String[] args)throws IOException{
    BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
    int t=Integer.parseInt(br.readLine());
    String s;
    char c[];
    for(int i=0;i<t;i++)
        {
		
    int r=0,g=0,b=0,w=0;
           s=br.readLine();
           c=s.toCharArray();
           
           for(int j=0;j<c.length;j++)
           {    
               if(c[j]=='R')
                   r++;
               if(c[j]=='G')
                   g++;
               if(c[j]=='B')
                   b++;
               if(c[j]=='W')
                   w++;   
           }
           if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
               System.out.println("YES");
           else
               System.out.println("NO");
        }
     }  
}
