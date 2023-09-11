#include<iostream>
using namespace std;

main()
{
char s[100];
int tc,i,r,g,b,w;;
cin>>tc;
while(tc--)
{	 
	cin>>s;
	for(i=0,r=0,g=0,b=0,w=0;s[i];i++)
	{					
		switch(s[i])
		{
		case 'R': r++;break;
		case 'G': g++;break;
		case 'B': b++;break;
		case 'W': w++;break;
		}
	}
r=r%2;
g=g%2;
b=b%2;
w=w%2;
if(r||g||b||w)
	cout<<"NO\n";
else
	cout<<"YES\n";
}
}
