import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;


class Sample
{

    public static void main(String[] args) throws IOException
    {
        BufferedReader br =new BufferedReader(new InputStreamReader(System.in));

        int tc=Integer.parseInt(br.readLine());
        int r=0,g=0,w=0,b=0;
        for(int i=0;i<tc;i++)
        {
            char[] st=br.readLine().toCharArray();

            if(st.length==0)
            {

            }

            for(int j=0;j<st.length;j++)
            {
                if(st[j]=='R')
                {
                    r++;
                }

                if(st[j]=='W')
                {
                    w++;
                }

                if(st[j]=='B')
                {
                    b++;
                }

                if(st[j]=='G')
                {
                    g++;
                }
            }

            if(r%2==0&&w%2==0&&g%2==0&&b%2==0)
            {
                System.out.println("YES");
            }
            else
            {
                System.out.println("NO");
            }

            r=0;
            g=0;
            w=0;
            b=0; //refresh
        }

    }

}
