import java.io.*;
class PairSocks1
{
    public static void main(String[] args)
    throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int i,j,t,col[]={0,0,0,0};
        String c;
        t=Integer.parseInt(br.readLine());
        int arr[]=new int[t];
        for(i=0;i<t;i++)
        {
            c=br.readLine();
            for(j=0;j<c.length();j++)
            {
                if(c.charAt(j)=='R')
                    col[0]=col[0]==0?1:0;
                if(c.charAt(j)=='G')
                    col[1]=col[1]==0?1:0;
                if(c.charAt(j)=='B')
                    col[2]=col[2]==0?1:0;
                if(c.charAt(j)=='W')
                    col[3]=col[3]==0?1:0;
            }
            if(col[0]==0 && col[1]==0 && col[2]==0 && col[3]==0) arr[i]=0;
            else arr[i]=1;
            col[0]=col[1]=col[2]=col[3]=0;
        }
        for(i=0;i<t;i++)
        {
            if(arr[i]==0)System.out.println("YES");
            else System.out.println("NO");
        }
    }
}