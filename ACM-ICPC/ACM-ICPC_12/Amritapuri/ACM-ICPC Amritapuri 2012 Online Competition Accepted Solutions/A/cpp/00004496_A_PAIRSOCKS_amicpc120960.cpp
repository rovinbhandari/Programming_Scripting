#include<iostream>
using namespace std;
int main()
{
	int t;
	cin>>t;
	for(int i=0;i<t;i++)
	{
		string s;
		cin>>s;
		int r=0,b=0,g=0,w=0;
	
		int l=s.size();
		for(int i=0;i<l;i++)
		{
			if(s[i]=='R')
				r++;
			else if(s[i]=='B')
				b++;
			else if(s[i]=='G')
				g++;
			else if(s[i]=='W')
				w++;
		}
		if((r%2==0) && (w%2==0) && (b%2==0) &&(g%2==0))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
	}
	return 0;
}