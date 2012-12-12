import java.util.*;

public class Main
{
	public static void main(String[] args)
        {
	try
	{
	int c=0,co=0;
	Scanner input=new Scanner(System.in);
	int a=input.nextInt();
	String[] s;
        char[] ch;
	if((a<1001) && (a>0))
		s=new String[a];
	else
		return;

	for(int i=0;i<a;i++)
	{
		s[i]=input.next();
		if(s[i].length()>=51)
			return;
                ch=s[i].toCharArray();
                for(int j=0;j<ch.length;j++)
                    if(ch[j]!='R'&&ch[j]!='G'&&ch[j]!='B'&&ch[j]!='W')
                           return;
	}
	for(int i=0;i<a;i++)
	{
		ch=s[i].toCharArray();
                s[i]="NO";
                Arrays.sort(ch);
		if(ch.length%2==0)
		{
		for(int j=0;j<ch.length;j+=2)
		{
			if(ch[j]!=ch[j+1])
			{
				c=1;
				break;
			}
		}
		}
                else
                    c=1;
		if(c==0)
		{
			s[i]="YES";
		}
		c=0;
	}
        for(int i=0;i<a;i++)
	{
        System.out.println(s[i]);
        }
	}
	catch(Exception e)
	{
		return;
	}
    }
}

