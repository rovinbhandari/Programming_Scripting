
import java.io.IOException;
import java.util.Scanner;

public class Main 
{
    public static void main(String[] args) throws IOException
    {
        int n=0;        
        Scanner in=new Scanner(System.in);
        String str=null,ans="";
        int cntr=0,cntg=0,cntb=0,cntw=0;
        try
        {
            n=in.nextInt();
            for(int i=0;i<=n;i++)
            {
                str=in.nextLine();
                for(int j=0;j<str.length();j++)
                {
                    if(str.charAt(j)=='R')
                        cntr++;
                    else if(str.charAt(j)=='G')
                        cntg++;
                    else if(str.charAt(j)=='B')
                        cntb++;
                    else if(str.charAt(j)=='W')
                        cntw++;
                }                
                if(cntr%2==0&&cntw%2==0&&cntg%2==0&&cntb%2==0)
                {
                    ans+="YES:";
                }
                else
                    ans+="NO:";
                cntr=0;cntw=0;cntb=0;cntg=0;
            }
            String f[]=ans.split(":");
            for(int i=1;i<f.length;i++)
                System.out.println(f[i]);
            in.close();
        }        
        catch(Exception e)
        {
            in.close();
            System.exit(0);
        }
        System.exit(0);   
}
    
}
