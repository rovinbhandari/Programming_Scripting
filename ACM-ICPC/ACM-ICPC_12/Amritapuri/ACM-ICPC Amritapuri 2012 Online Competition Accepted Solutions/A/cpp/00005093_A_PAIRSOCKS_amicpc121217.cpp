#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    char a[100];
	int w,r,b,g,l,t,i;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
	 w=0;r=0;b=0;g=0;
	cin>>a;

	l=strlen(a);
		for(i=0;i<l;i++)
		{
		 if(a[i]=='W')
		 {
		 	w++;
		 }
		 else if(a[i]=='R')
		 {
		 	r++;
		 }
		 else if(a[i]=='B')
		 {
		 	b++;
		 }
		 else if(a[i]=='G')
		 {
		 	g++;
		 }
		}
	
	if(w%2==0 && r%2==0 && b%2==0 && g%2==0)
	{
	cout<<"YES"<<"\n";
	
	}
	else
	cout<<"NO"<<"\n";

}
	return 0;
}
