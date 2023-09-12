#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;

int main()
{
int i,j,k,l,m,n,t,x1=0,x2=0,x3=0,x4=0;
cin>>t;
while(t--)
{
    x1=0;
    x2=0;
    x3=0;
    x4=0;
    char a[100];
    cin>>a;
    j=strlen(a);
    for(i=0;i<j;i++)
    {
    if(a[i]=='R')
    x1++;
    else if(a[i]=='G')
    x2++;
    else if(a[i]=='B')
    x3++;
    else
    x4++;

    }
    //cout<<x1<<" "<<x2<<" "<<x3<<" "<<x4<<" ";
if(x1%2==0 && x2%2==0 && x3%2==0 && x4%2==0)
cout<<"YES\n";
else
cout<<"NO\n";


}
    return 0;
}


