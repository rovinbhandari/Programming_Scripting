#include<iostream>
using namespace std;

int main()
{
	int T;
	cin>>T;
	if(1<=T<=50)
	{
		int i,j,R,G,B,W;
		for(j=0;j<T;j++)
		{
		R=G=B=W=0;
		char c[51];
		cin>>c;
		for(i=0;c[i]!='\0';i++)
		{
			if(c[i]=='R')
				R++;
			else if(c[i]=='G')
				G++;
			else if(c[i]=='B')
				B++;
			else if(c[i]=='W')
				W++;
		}
		if((W%2==0)&&(B%2==0)&&(G%2==0)&&(R%2==0))
			cout<<"YES"<<endl;
		else
			cout<<"NO"<<endl;
		}
	}
	return 0;
}