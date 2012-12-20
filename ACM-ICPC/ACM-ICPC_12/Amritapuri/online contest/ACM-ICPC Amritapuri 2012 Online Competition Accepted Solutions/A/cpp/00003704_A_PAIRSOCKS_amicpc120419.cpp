#include<iostream>
#include<cstring>
using namespace std;
int main()
{	int t;
	char a[51];
	char ch;
	cin>>t;
	while(t--)
	{	cin>>a;
		int r=0,g=0,w=0,b=0;	
		int j=0;
		int k=strlen(a);
		while(j<k)
		{	
			if(a[j]=='R')
				r++;
			if(a[j]=='G')
				g++;
			if(a[j]=='B')
				b++;
			if(a[j]=='W')
				w++;
			j++;
		}
	if(r%2==0&&b%2==0&&g%2==0&&w%2==0)
		cout<<"YES"<<"\n";
	else
		cout<<"NO"<<"\n";
	}
}
