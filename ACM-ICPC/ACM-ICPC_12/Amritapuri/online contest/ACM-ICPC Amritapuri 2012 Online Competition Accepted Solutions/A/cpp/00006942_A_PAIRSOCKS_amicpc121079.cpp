#include<iostream>
#include<string.h>
using namespace std;

main()
{
	int f[4];
	int n,t,j,i,k;
	

	cin>>t;
	char a[t][50];
		
	for(i=0;i<t;i++)
	{
		cin>>a[i];
	
	

	
		for(k=0;k<4;k++)
		{
			f[k]=0;
		}

		n=strlen(a[i]);

		for(j=0;j<n;j++)
		{

			if(a[i][j]=='R')
			{
				f[0]++;
			}
			else if(a[i][j]=='G')
			{
				f[1]++;
			}
			else if(a[i][j]=='B')
			{
				f[2]++;
			}
			else if(a[i][j]=='W')
			{
				f[3]++;
			}



		}

		for(k=0;k<4;k++)
		{

			if(f[k]%2!=0)
			{
				cout<<"NO"<<endl;
				break;
			}
		}

		if(k==4)
		{
			cout<<"YES"<<endl;
		}
	}

}
