import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.ArrayList;
import java.util.List;

/**
 *
 * @author Arun
 */
public class Socks {
    static int countChar(char c,String str)
    {
        int count=0;
        for(int i=0;i<str.length();i++)
        {
            if(str.charAt(i)==c)
            {
                count=count+1;
            }
        }
        return count;
    }

    public static void main (String args[]) throws IOException
    {
        int r=0,g=0,b=0,w=0;
        BufferedReader buf=new BufferedReader (new InputStreamReader(System.in));
        int number=Integer.parseInt(buf.readLine());
         List<String> output = new ArrayList<String>();

        for(int i=0;i<number;i++)
        {
           String str=buf.readLine();
           String temp=new String();
          // input.add(str);
          r=countChar('R',str);
          g=countChar('G',str);
          b=countChar('B',str);
          w=countChar('W',str);
          if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
          {
              output.add("YES");
          }
          else
              output.add("NO");

        }
        for(int i=0;i<output.size();i++)
        {
            System.out.println(output.get(i));
        }
    }
}
