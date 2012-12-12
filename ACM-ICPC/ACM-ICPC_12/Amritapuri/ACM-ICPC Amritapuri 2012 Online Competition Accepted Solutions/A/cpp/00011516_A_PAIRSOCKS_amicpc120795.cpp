#include<iostream>
#include<algorithm>
#include<string.h>
using namespace std;

int main()
{	int test;
	cin>>test;
	while(test--)
	{	char ch[51];
		int l, ar[4]={0}, x, flag=1;
		cin>>ch;
		l=strlen(ch);
		for(int i=0; i<l; ++i)
		{	ch[i]=toupper(ch[i]);
			switch(ch[i])
			{
			case 'R':
				ar[0]++;
				break;
			case 'B':
				ar[1]++;
				break;
			case 'G':
				ar[2]++;
				break;
			case 'W':
				ar[3]++;
				break;
			default:
				return 0;
			}
		}
		for(x=0; x<4; ++x)
			if(ar[x]%2!=0)
			{	flag=0;
				break;
			}
		if(flag==0)
			cout<<"NO"<<endl;
		else
			cout<<"YES"<<endl;
	}
	return 0;
}
