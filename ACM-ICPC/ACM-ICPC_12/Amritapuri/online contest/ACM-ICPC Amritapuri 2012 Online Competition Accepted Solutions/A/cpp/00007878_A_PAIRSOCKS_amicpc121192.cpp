#include<iostream>
#include<string.h>
int main()
{
	int t,i,j,m;
	int r,b,w,g;
	char c[50];
	int sol[1000];
	std::cin>>t;
	for(i=0;i<t;i++)
	{
		std::cin>>c;
		r=0;b=0;w=0;g=0;
		m=strlen(c);
		for(j=0;j<m;j++)
		{
			if(c[j]=='R')
				r++;
			if(c[j]=='G')
				g++;
			if(c[j]=='B')
				b++;
			if(c[j]=='W')
				w++;
		}
		if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
			sol[i]=1;
		else
			sol[i]=0;
	}
	for(i=0;i<t;i++)
	{
	if(sol[i]==1)
		std::cout<<"YES"<<std::endl;
	else
		std::cout<<"NO"<<std::endl;
	}
	return 0;
}