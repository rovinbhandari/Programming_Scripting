#include<iostream>
#include<stdlib.h>
#include<string.h>
#include"../include/postfix.h"
using namespace std;

int postfix(char c[])
{
	char a[20], f[20];
	int i=0, l=0, d, e, b[20],m,n;
	f[l]='\0';
	for(m=0;c[i]!='\0';i++)
	{
		if(c[i]>=48 && c[i]<=57)
		{
			a[m]=c[i];
			m++;
		}
		else if(c[i]>=42 && c[i]<=47)
		{
			if(f[l]=='\0')
			{
				f[l]=c[i];
			}
			else if(c[i]==42 || c[i]==47)
			{	
				while(f[l]==42 || f[l]==47)
				{
					a[m]=f[l];
					m++;
					l--;
				}
				l++;
				f[l]=c[i];
			}
			else if(c[i]==43 || c[i]==45)
			{
				while(l>=0)
				{
					a[m]=f[l];
					m++;
					l--;
				}
				l++;
				f[l]=c[i];				
			}
			else
			{
				l++;
				f[l]=c[i];
			}
		}	
		//cout<<c[i]<<" "<<f[l]<<" "<<a[m]<<endl;
		//for(n=l;n>=0;n--)
		//	cout<<f[n];
		//cout<<endl;		
	}
	while(l>=0)
	{
		a[m]=f[l];
		m++;
		l--;
	}
	a[m]='\0';
	cout<<"\nPostfix expression : \n";
	for(i=0;a[i]!='\0';i++)
		cout<<a[i]<<endl;
		
	for(i=0,l=0;a[i]!=0;i++)
	{	
		if(a[i]>=48 && a[i]<=57)
		{
			b[l] = a[i]-'0';
			l++;
			
		}
		else if(a[i] == 43)
		{	
			l--;
			d=b[l];b[l]=0;l--;
			e=b[l];b[l]=d+e;
			l++;			
		}
		else if(a[i] == 45)
		{	
			l--;
			d=b[l];b[l]=0;l--;
			e=b[l];b[l]=e-d;
			l++;			
		}
		else if(a[i] == 42)
		{	
			l--;
			d=b[l];b[l]=0;l--;
			e=b[l];b[l]=d*e;
			l++;			
		}
		else if(a[i] == 47)
		{	
			l--;
			d=b[l];b[l]=0;l--;
			e=b[l];b[l]=e/d;
			l++;			
		}
	}
	l--;
	return b[l];
}
