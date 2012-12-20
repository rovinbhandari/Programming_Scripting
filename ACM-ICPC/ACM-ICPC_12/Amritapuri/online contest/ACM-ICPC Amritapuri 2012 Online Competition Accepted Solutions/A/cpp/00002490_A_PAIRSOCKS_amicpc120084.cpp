#include<iostream>
using namespace std;
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;i++)
	{
		string str;
		cin>>str;
		int r=0,g=0,b=0,w=0;
		for(int j=0;j<str.size();j++)
			if(str[j]=='R')
				r++;
			else if(str[j]=='G')
				g++;
			else if(str[j]=='B')
				b++;
			else if(str[j]=='W')
				w++;
		if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}
