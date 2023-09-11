#include<iostream>
//#include<string>

using namespace std;

int main(){
string s;int t;
cin>>t;
for(int i=1;i<=t;i++)
	{
	int c1=0,c2=0,c3=0,c4=0;
	cin>>s;
	int l=s.length();
	for(int j=0;j<l;j++)
		{
		if(s[j]=='R')
			c1++;
		else if(s[j]=='G')
			c2++;
		else if(s[j]=='B')
			c3++;
		else 
			c4++;
		}
	if(c1%2==0 && c2%2==0 && c3%2==0 && c4%2==0)
		cout << "YES\n";
	else 
	 cout <<"NO\n";
	}

}
