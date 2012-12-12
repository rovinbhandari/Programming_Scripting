import java.util.*;
import java.io.*;
class Pair
{
	public static void main(String args[])
	{
	int num=0,i=0,posr=0,posg=0,posb=0,posw=0,len=0,k=2;
	String no,str,strsorted;
	char ch[];
	Scanner in=new Scanner(System.in);
	no=in.nextLine();
	num=Integer.parseInt(no);
	String s[]=new String[num];
		for(i=0;i<num;i++)
		{
		str=in.nextLine();
		ch=str.toCharArray();
		Arrays.sort(ch);
		strsorted=new String(ch);
		len=strsorted.length();
		posb=strsorted.indexOf('B',0)-strsorted.lastIndexOf('B')+1;
		if(strsorted.indexOf('B',0)==-1) posb=0;

		posg=strsorted.indexOf('G',0)-strsorted.lastIndexOf('G')+1;
		if(strsorted.indexOf('G',0)==-1) posg=0;

		posr=strsorted.indexOf('R',0)-strsorted.lastIndexOf('R')+1;
		if(strsorted.indexOf('R',0)==-1) posr=0;

		posw=strsorted.indexOf('W',0)-strsorted.lastIndexOf('W')+1;
		if(strsorted.indexOf('W',0)==-1) posw=0;

	if(((posb)%k==0)&&((posg)%k==0)&&((posr)%k==0)&&((posw)%k==0))
			{
			s[i]=new String("YES");
			}
			else
			{
			s[i]=new String("NO");
			}
		}
		for(i=0;i<num;i++)
		System.out.println(s[i]);
	}
}