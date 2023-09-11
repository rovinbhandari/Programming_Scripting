#include<iostream>
#include<string>
using namespace std;
int main()
{
int t;
int strlen;
int *res;

cin>>t;
res=new int[t];
string input;
int i;
for(i=0;i<t;i++)
{
cin>>input;
strlen=input.length();
if(strlen%2!=0)
{
*(res+i)=0;
}
else
{
int r=0,g=0,b=0,w=0;
for(int j=0;j<strlen;j++)
	{
	if(input[j]=='R')
	r++;
	else if(input[j]=='G')
	g++;
	else if(input[j]=='B')
	b++;
	else 
	w++;
	}
if((r%2==0)&&(g%2==0)&&(b%2==0)&&(w%2==0))
*(res+i)=1;
else
*(res+i)=0;
}
}
for(int k=0;k<t;k++)
{
if(*(res+k)==1)
cout<<"YES\n";
else
cout<<"NO\n";
}
return 0;
}
