#include<iostream>
#include<cstring>

using namespace std;

int main()
{
	int T;
	cin>>T;
	int i;
	for(i=0;i<T;i++)
	{
		int num[4];
		for(int k=0;k<4;k++)
			num[k]=0;
		string socks;
		cin>>socks;
		int len=socks.length();
		int j;
		for(j=0;j<len;j++)
		{
			if(socks[j]=='R')
				num[0]++;
			else if(socks[j]=='G')
				num[1]++;
			else if(socks[j]=='B')
				num[2]++;
			else if(socks[j]=='W')
				num[3]++;
		}
		if(((num[0]%2)==0)&&((num[1]%2)==0)&&((num[2]%2)==0)&&((num[3]%2)==0))
			cout<<"YES"<<endl;
		else 
			cout<<"NO"<<endl;
	}
	return 0;
}
