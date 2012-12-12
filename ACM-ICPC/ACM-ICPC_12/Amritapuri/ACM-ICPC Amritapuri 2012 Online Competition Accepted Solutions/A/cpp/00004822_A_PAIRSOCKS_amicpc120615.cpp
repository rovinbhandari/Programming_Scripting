#include<iostream>
#include<stdio.h>
using namespace std;

int main()
{
	int T,r,g,b,w,i;
	char s[100];

	cin>>T;
	while(T)
	{
		cin>>s;
		r=0;
                g=0;
                b=0;
                w=0;
		//cout<<s<<endl;
		for(i=0;s[i]!='\0';i++)
		{
			switch(s[i])
			{
				case 'R' : r++;
				break;
				case 'G' : g++;
                                break;
				case 'B' : b++;
                                break;
                                case 'W' : w++;
                                break;
			}
		//cout<<s[i]<<endl;
		}
		//cout<<r<<b<<g<<w;
		if ((r%2)||(b%2)||(g%2)||(w%2))
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
		}
		T--;
	}
}
