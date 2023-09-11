import java.io.*;
public class main
{
    public static void main(String[] args)throws IOException
    {
        InputStreamReader read=new InputStreamReader(System.in);
        BufferedReader in=new BufferedReader(read);
        
        int t=0,i=0,j=0,r=0,b=0,g=0,w=0;
        String s;
        t=Integer.parseInt(in.readLine());
        int retval[]=new int[t];
        
        for(i=0;i<t;i++)
        {
            s=in.readLine();
            
            for(j=0;j<s.length();j++)
            {
                switch(s.charAt(j))
                {
                    case 'R':
                    r++;
                    break;
                    case 'B':
                    b++;
                    break;
                    case 'G':
                    g++;
                    break;
                    case 'W':
                    w++;
                    break;
                    default:
                    System.out.println("Wrong Input");
                    break;
                }
            }
            if(r%2==0 && b%2==0 && g%2==0 && w%2==0)
            {
                retval[i]=1;
            }
            else
            {
                retval[i]=0;
            }
            r=0;g=0;w=0;b=0;
        }
        
        for(i=0;i<t;i++)
        {
            if(retval[i]==1)
            {
                System.out.println("YES");
            }
            else
            {
                System.out.println("NO");
            }
        }
    }
}
