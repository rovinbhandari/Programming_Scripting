#include<iostream>
#include<string.h>
using namespace std;
main()
{
	char **p;
	int n;
	cin>>n;
	p=new char*[n];
	int i,j;
	for(i=0;i<n;i++)
	{
		p[i]=new char[50];
		}
	for(i=0;i<n;i++)
	{
		cin>>p[i];
		}
	bool r=0,g=0,b=0,w=0;
	for(i=0;i<n;i++)
	{
		for(j=0;j<strlen(p[i]);j++)
		{
			switch(p[i][j])
			{
				case 'R': r=!r; break;
				case 'G': g=!g; break;
				case 'W': w=!w; break;
				case 'B': b=!b; break;
			}
		}
		if(g==0 && b==0 && r==0 && w==0)
		cout<<"YES"<<endl;
		else
		cout<<"NO"<<endl;
		r=g=w=b=0;
	}
}
