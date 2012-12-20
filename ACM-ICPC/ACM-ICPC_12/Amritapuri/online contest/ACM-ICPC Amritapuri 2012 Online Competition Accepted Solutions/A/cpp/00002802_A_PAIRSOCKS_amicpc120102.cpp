#include<iostream>
#include<map>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		//R: 0 B:1 G:2 W:3
		map<char,int> sock;
		sock['R']=0;
		sock['G']=1;
		sock['B']=2;
		sock['W']=3;
		int count[5]={0};
		for(int i=0;i<s.length();i++)
		{
			count[sock[s[i]]]++;
		}
		int flg=0;
		for(int i=0;i<4;i++)
		{
			if(count[i]%2!=0)
			{
				flg=1;
				break;
			}
		}
		if(flg==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;

	}

	return 0;
}
