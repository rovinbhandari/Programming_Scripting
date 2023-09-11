#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	int T;
	cin>>T;
	
	int output[T];
	
	for(int j =0;j<T;j++)
	{
		char s[50];
		int r=0,b=0,g=0,w=0,flag;
		cin>>s;
		
		if(strlen(s)%2 != 0)
			output[j] = 0;
		else
		{
			for(int i=0;s[i]!=0;i++)
			{
				if(s[i]=='R')
					r++;
				else if(s[i]=='B')
					b++;
				else if(s[i]=='W')
					w++;
				else if(s[i]=='G')
					g++;
				
				
			}
			if(r%2==0 && b%2==0 && w%2==0 && g%2==0)
				output[j] = 1;
			else
				output[j] = 0;
		}
	}
	
	for(int j =0;j<T;j++)
	{
		if(output[j] == 1)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	
	return 0;
}