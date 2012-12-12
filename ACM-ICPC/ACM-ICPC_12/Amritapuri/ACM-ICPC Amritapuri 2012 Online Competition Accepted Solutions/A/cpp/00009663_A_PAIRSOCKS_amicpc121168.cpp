#include<iostream>
using namespace std;
int main()
{
int i,t,j,k;
int r=0,g=0,b=0,w=0,res[5];
char c[50];
cin>>t;
if(t>1000)
{  return 0;}
else
{
	for(j=0;j<t;j++)
	{
		cin>>c;
        	r=0;g=0;b=0;w=0;
		for(i=0;c[i]!='\0';i++)	
		{
			if(c[i]=='R'){r=r+1;}
			else if(c[i]=='G'){g=g+1;}
			else if(c[i]=='W'){w=w+1;}
			else if(c[i]=='B'){b=b+1;}
		}
      
	if((r%2)||(g%2)||(b%2)||(w%2))
	{
		cout<<"NO\n";
	}
	else
	{
		cout<<"YES\n";
	}
	}
}
}

