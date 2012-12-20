#include<iostream>
#include<string>
using namespace std;
static int r=0,b=0,g=0,w=0,k=0;
int a[100];
int main()
{
	int t,limit=1,i;
	string str;
	cin>>t;
	while(limit<=t)
	{
	        cin>>str;
	
		for(i=0;i<str.length();i++)
		{
			if(str[i]=='R')
			  r++;
			else if (str[i]=='B')
			  b++;
			else if (str[i]=='G')
			  g++;
			else
			  w++;
	        }  
                  
		if (r%2==0 && b%2==0 && g%2==0 && w%2==0)
		{
			cout<<"YES\n";
		    r=0;b=0;g=0;w=0;
		}
		else
		{
			cout<<"NO\n";
		     r=0;b=0;g=0;w=0;
		}
		limit++;
		}
		
}
