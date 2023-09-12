#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main()
{
string s;
int t,i,n,j;

cin>>t;
for(i=0;i<t;i++)
{
int countr=0,countg=0,countb=0,countw=0;
	cin>>s;
	n=s.length();
	if(n%2==0)
	{

	for(j=0;j<n;j++)
		{
	
		if(s[j]=='R')
		countr++;
	        
 		if(s[j]=='G')
		countg++;

		if(s[j]=='B')
		countb++;

		if(s[j]=='W')
		countw++;
        	}
        
        if(countr%2==0 && countg%2==0 && countb%2==0 && countw%2==0)
		{        
		cout<<"YES";
		cout<<"\n";
        	}
		else
		{
		goto a;
		}
}
else
{
a:
cout<<"NO";
cout<<"\n";
}



}

return 0;
}
