#include<iostream>
#include<map>
#include<math.h>
#include<stdio.h>

using namespace std;
int main()
{
int test;
cin>>test;
while(test--)
{
int n,m;
cin>>n>>m;
int ar[n],bx[m][3];
for(int i=0;i<n;i++)
{
cin>>ar[i];
}
for(int i=0;i<m;i++)
{
cin>>bx[i][0]>>bx[i][1]>>bx[i][2];
}
double maxlen=-100000000;
for(int i=0;i<m;i++)
{
maxlen=max(maxlen,(double)max(bx[i][0],max(bx[i][1],bx[i][2])));
double a=sqrt(pow((bx[i][0]),2)+pow((bx[i][1]),2));
double b=sqrt(pow((bx[i][0]),2)+pow((bx[i][2]),2));
double c=sqrt(pow((bx[i][2]),2)+pow((bx[i][1]),2));
maxlen=max(maxlen,max(b,max(a,c)));
a=sqrt(pow((bx[i][2]),2)+pow((bx[i][0]),2)+pow((bx[i][1]),2));
maxlen=max(maxlen,a);
}
int cnt=0;
for(int i=0;i<n;i++)
{
if((double)(ar[i])<=maxlen)
cnt++;
}
cout<<cnt<<"\n";
}
return 0;
}
