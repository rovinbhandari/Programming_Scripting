//Problem A:Pair Socks
#include <iostream>
#include<string.h>
using namespace std;
#define max 50

int main()
{
	int T; 
	cin>>T;
	if(T<1 || T>1000)
	 return 0;
	for(int kase = 1; kase <= T; kase++)
	{
		char c[max];
		cin>>c;
 		int l=strlen(c);
		int rcnt=0,gcnt=0,bcnt=0,wcnt=0;
		for(int i=0; i<l; i++)
		{
			if(c[i]=='R')
			  rcnt++;
			else if(c[i]=='G')
			  gcnt++;
			else if(c[i]=='B')
			  bcnt++;
			else if(c[i]=='W')
			  wcnt++;
  			else
			 return 0;
		}
		if(rcnt%2==0 && gcnt%2==0 && bcnt%2==0 && wcnt%2==0)
		 cout <<"YES"<<endl;
                else
		 cout <<"NO"<<endl;
	}
	return 0;
}
