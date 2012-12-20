import java.io.*;
public class pair_socks
{
	
    
    public static void main(String args[])throws IOException
    {
    	char cr[]={'R','G','B','W'};
    	BufferedReader don=new BufferedReader(new InputStreamReader(System.in));
        String ip;
        //System.out.println("Enter the test cases");
        int t=Integer.parseInt(don.readLine());
        boolean op[]=new boolean[t];
        int cnt[]=new int[4];
        int l;
        for(int i=0;i<t;i++)
        {
            for(int j=0;j<4;j++)
            cnt[j]=0;
            ip=don.readLine();
            l=ip.length();
            for(int j=0;j<l;j++)
            {
                for(int k=0;k<4;k++)
                {
                    if(ip.charAt(j)==cr[k])
                    cnt[k]=(cnt[k]+1)%2;
                }
            }
            op[i]=true;
            for(int j=0;j<4;j++)
            if(cnt[j]!=0)
            op[i]=false;
        }
        for(int i=0;i<t;i++)
        {
            if(op[i])
            System.out.println("YES");
            else
            System.out.println("NO");
        }
    }

}
