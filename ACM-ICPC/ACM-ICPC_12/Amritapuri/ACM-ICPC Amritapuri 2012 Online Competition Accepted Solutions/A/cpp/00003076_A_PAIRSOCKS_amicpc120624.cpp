#include<iostream>
#include <string.h>
using namespace std;

int main()
{
	int t,r,g,b,w,i,n;
	string s;
	
	cin>>t;
	cin.get();
	while(t!=0)
	{
		r=g=b=w=0;
		getline(cin,s);
		n=s.length();
		if(n%2==0)
		{
		for(i=0;i<n;i++)
		{
			
			
			switch(s[i])
			{
				case 'R':r++;break;
				case 'G':g++;break;
				case 'B':b++;break;
				case 'W':w++;break;

				
			}
			
		}
		if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
		cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
		}
		else cout<<"NO"<<endl;
		t--;
	}
	return 0;
}
