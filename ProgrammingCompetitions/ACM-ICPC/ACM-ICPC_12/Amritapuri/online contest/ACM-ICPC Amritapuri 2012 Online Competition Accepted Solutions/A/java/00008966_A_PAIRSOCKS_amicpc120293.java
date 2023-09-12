import java.io.*;
public class socks
{
	public static void main(String args[]) throws IOException
	{
		BufferedReader in = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(in.readLine());
        int l=t;
        int w=0,r=0,g=0,b=0,i=0;
        String op[]=new String[t];
        while (t-- > 0) 
        {
        	String s=in.readLine();
        	char c[];
        	c=s.toCharArray();
        	int j=0;
        	w=0;r=0;g=0;b=0;
        	while(j<s.length())
        	{
        		inner: switch(c[j])
        		{
        			case 'W':
        			w++;break inner;
        			case 'R':
        			r++;break inner;
        			case 'G':
        			g++;break inner;
        			case 'B':
        			b++;break inner;	
        		}
        		j++;
        	}
        	if((w%2==0)&&(r%2==0)&&(g%2==0)&&(b%2==0))
        	op[i]="YES";
        	else
        	op[i]="NO";
        	i++;
        }
        i=-1;
        while(++i < l)
        System.out.println(op[i]);

	}
}