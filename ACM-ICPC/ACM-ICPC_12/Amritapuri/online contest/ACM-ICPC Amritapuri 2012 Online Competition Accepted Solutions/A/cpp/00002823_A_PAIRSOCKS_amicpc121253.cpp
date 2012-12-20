#include<iostream>
#include<map>
#include<string>
using namespace std;
int main()
{
	map<char,int> data;
	map<char,int>::iterator it;
	int t;
	cin>>t;
	string temp;
	for(int i=0;i<t;i++)
	{
		cin>>temp;
		for(unsigned int i=0;i<temp.length();i++)
				++data[temp[i]];
		bool flag = true;
		for(it=data.begin();it!=data.end();it++)
		{
			if((*it).second%2!=0)
				{flag =false;
				 break;}
		}
		if(flag)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		data.clear();
	}
return 0;
}
