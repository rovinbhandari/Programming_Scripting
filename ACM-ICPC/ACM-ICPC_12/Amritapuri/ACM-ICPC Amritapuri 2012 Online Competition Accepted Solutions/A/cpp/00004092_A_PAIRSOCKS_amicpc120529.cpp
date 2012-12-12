#include <iostream>
#include<string.h>
using namespace std;
int main()
{
int i,x,r=0,b=0,g=0,w=0;
 char q[1000][51];
cin>>i;

for(int k=0;k<i;k++)
	{
	cin>>q[k];
	}

for(int l=0;l<i;l++)
	{r=b=g=w=0;
	x=strlen(q[l]);
		for(int t=0;t<x;t++)
			{switch(q[l][t])
				{case 'R' : r++;break;
				case 'W' : w++;break;
				case 'B' : b++;break;
				case 'G' : g++;break;
				}
			}
		if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
		  cout<<"YES"<<endl;
		  else cout<<"NO"<<endl;
	}
	return 0;
}
