#include<iostream>
#include<string.h>
using namespace std;
class sock
{
public:
char c[50];
int R1,B1,W1,G1,flag;
sock()
{
R1=0;
B1=0;
W1=0;
G1=0;
flag=0;
}
};
int main()
{sock ob[1000];
int N,n,i,j;
cin>>N;
for(i=0;i<N;i++)
{
cin>>ob[i].c;
}
for(i=0;i<N;i++)
{
n=strlen(ob[i].c);
for(j=0;j<n;j++)
{
switch(ob[i].c[j])
{
case 'R' : ob[i].R1++;
           break;
case 'B' : ob[i].B1++;
           break;
case  'W':ob[i]. W1++;
           break;
case  'G':ob[i].G1++;
          break;
default :
           ob[i].flag++;
 cout<<"NO"<<'\n';
}
}

if((ob[i].R1%2==0) && (ob[i].G1%2==0) && (ob[i].B1%2==0) && (ob[i].W1%2==0) && (ob[i].flag==0))
{
cout<<"YES"<<'\n';
}
else
cout<<"NO"<<'\n';
} 
}


