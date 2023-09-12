import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.OutputStreamWriter;
import java.io.PrintWriter;

/**
 *
 * @author abhishek khanna
 */
public class Main {

    /**
     * @param args the command line arguments
     */
    public static void main(String[] args) throws IOException 
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        PrintWriter pw=new PrintWriter(new OutputStreamWriter(System.out));
        int test=Integer.parseInt(br.readLine());
        for(int j=0;j<test;j++)
        {
            String s=br.readLine();
            int r=0,g=0,b=0,w=0;
            for(int i=0;i<s.length();i++)
            {
                if(s.charAt(i)=='R')
                {
                    r++;
                }
                else if(s.charAt(i)=='G')
                {
                    g++;
                }
                else if(s.charAt(i)=='B')
                {
                    b++;
                }
                else
                {
                    w++;
                }
            }
            if(r%2==0 && g%2==0 && b%2==0 &&w%2==0)
            {
                pw.println("YES");
            }
            else
            {
                pw.println("NO");
            }
        }
        pw.flush();
        // TODO code application logic here
    }

}
