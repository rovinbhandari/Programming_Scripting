#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>
#include<algorithm>
#include<vector>
using namespace std;
int main()
{
int t;
scanf("%d",&t);
for(int ii=0;ii<t;ii++)
{
char a[100];
cin>>a;
int rc=0,gc=0,bc=0,wc=0;
int l=strlen(a);
for(int i=0;i<l;i++)
{
if(a[i]=='R')
rc++;
if(a[i]=='G')
gc++;
if(a[i]=='B')
bc++;
if(a[i]=='W')
wc++;

}
if((rc%2==0)&&(gc%2==0)&&(bc%2==0)&&(wc%2==0))
cout<<"YES\n";
else cout<<"NO\n";
}
return 0;
}
