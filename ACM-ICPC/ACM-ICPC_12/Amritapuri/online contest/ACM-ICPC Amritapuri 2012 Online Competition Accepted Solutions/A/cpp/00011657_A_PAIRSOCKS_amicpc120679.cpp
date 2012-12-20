#include<iostream>
//#include<stdio.h>
#include<string.h>
#include<stdlib.h>

using namespace std;

main()
{
	int n,i,j;
	cin>>n;
if(n>=1&&n<=1000)
{
		
	char st[50];
	int a[n],bl[n],c[n],d[n],flag[n];
for(i=0;i<n;i++)
	{
	a[i]=0;
	bl[i]=0;
	c[i]=0;
	d[i]=0;
  int r=0,g=0,b=0,w=0;
//   cout<<"outer\n";
//cout<<i;
	
    cin>>st;
    for(j=0;j<strlen(st);++j)
    {
//	cout<<"enter inner\n";
      if(st[j]=='R')
	{
//	a[i]=0;
//	r++;
	a[i]=++r;
//	cout<<a[i]<<"a[i]\n";
	}
      if(st[j]=='G')
	{
//	bl[i]=0;
//	g++;
	bl[i]=++g;
//	cout<<bl[i]<<"bl[i]\n";
	}	
      if(st[j]=='B')
	{
//	c[i]=0;
//	b++;
	c[i]=++b;
//	cout<<c[i]<<"c[i]\n";
	}
      if(st[j]=='W')
	{
//	d[i]=0;
//	w++;
	d[i]=++w;
//	cout<<d[i]<<"d[i]\n";
	}
    }
   
  }
  for(i=0;i<n;i++)
{
//cout<<a[i]<<bl[i]<<c[i]<<d[i];  
   if((a[i]%2==0) && (bl[i]%2==0) && (c[i]%2==0) && (d[i]%2==0))
//	flag[i]=1;
      cout<<"YES\n";
    else
//	flag[i]=0;
      cout<<"NO\n";
  }
//for(i=0;i<n;i++)
//{
//	if(flag[i]==1)
//	{
//		cout<<"YES\n";
//	}
//	else
//	{
//		cout<<"NO\n";
//	}
//}
} 
}  
