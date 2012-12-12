#include<iostream>
#include<string.h>
using namespace std;

main()
{
	int i,j,t,count1=0,count2=0,count3=0,count4=0;
	cin>>t;
	int flag[t];
	string s;
	for(j=0;j<t;j++)
	{
		cin>>s;
		count1=0;count2=0;count3=0;count4=0;
	if(t>=1&&t<=1000&&s.length()%2==0)
	{
		i=0;
		while(s[i]=='R'||s[i]=='G'||s[i]=='W'||s[i]=='B')
		{
			i++;
		}
	if(i==s.length())
	{
		for(i=0;i<s[i]!='\0';i++)
		{
				if(s[i]=='R')
			{
				count1++;
				
			}
			
			if(s[i]=='G')
			{
				count2++;
			}
			
			if(s[i]=='B')
			{
				count3++;
			}
			
			if(s[i]=='W')
			{
				count4++;
			}
			
		}
	
	
		if(count1%2==0&&count2%2==0&&count3%2==0&&count4%2==0)
		{
			flag[j]=1;
		}

		
		
		else
		{
			flag[j]=0;
		}
	}

	
	}

	else
	{
		flag[j]=0;
	}

	}
	
	for(i=0;i<t;i++)
	{
		if(flag[i]==1)
		{
			cout<<"YES\n";
		}
		
		else
		{
			cout<<"NO\n";
		}
	}
}
