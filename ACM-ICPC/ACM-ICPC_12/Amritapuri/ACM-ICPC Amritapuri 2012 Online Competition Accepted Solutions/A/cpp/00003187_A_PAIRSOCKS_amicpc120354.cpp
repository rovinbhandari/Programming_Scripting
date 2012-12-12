#include<iostream>
#include<string>
using namespace std;
int a,b,c,d;
int main()
{
 	int n;
 	string s;
 	cin>>n;
 	while(n--)
 	{
     cin>>s;
     a=0;b=0;c=0;d=0;
 	for(int i=0;i<s.size();i++)
 	{
	 		if(s[i]=='R')
	 		a++;
	 		else if(s[i]=='G')
	 		b++;
	 		else if(s[i]=='W')
	 		c++;
	 		else if(s[i]=='B')
	 		d++;
    }
    if(!(a%2)&&!(b%2)&&!(c%2)&&!(d%2))
    cout<<"YES\n";
    else 
    cout<<"NO\n";
	}
}
	 		
