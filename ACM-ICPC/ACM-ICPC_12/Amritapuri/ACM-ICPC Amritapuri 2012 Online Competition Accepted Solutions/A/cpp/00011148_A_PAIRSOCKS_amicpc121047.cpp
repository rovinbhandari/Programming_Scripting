#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
	int i,j,k,T, flagg=0,flagr=0,flagb=0,flagw=0;
	char c[1000][51];
	cin>>T;
	if(T<=1000&&T>=1){
	j=0;	
	for(i=0;i<T;++i)
	{
			
		scanf("%s",c[i]);
		
	}	

	for(k=0;k<T;++k)
	{
		j=0;
		while(c[k][j])
		{	
			switch(c[k][j])
			{
				case 'R': flagr++; break;
				case 'G': flagg++; break;
				case 'B': flagb++; break;
				case 'W': flagw++; break;
			}
			++j;
		}
		if((flagg%2==0)&&(flagw%2==0)&&(flagr%2==0)&&(flagb%2==0))
		{
			cout<<"YES\n";
		}
		else
		{
			cout<<"NO\n";
		}
		flagg=0;
		flagw=0;
		flagr=0;
		flagb=0;

	}
}
}