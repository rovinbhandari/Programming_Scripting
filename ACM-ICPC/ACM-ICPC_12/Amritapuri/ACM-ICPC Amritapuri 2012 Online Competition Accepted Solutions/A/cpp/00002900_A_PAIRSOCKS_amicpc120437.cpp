#include<iostream>
#include<cstdlib>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<vector>
#include<string>
#include<algorithm>
#include<set>
using namespace std;

struct node
{
string A,B;
int c;
};
//req are : an array of pointers and some nodes

bool operator< (const node& a,const node& b)
{
/*bool t=0,k=0;
int i;
int m=min(strlen(a.A),strlen(b.A));
for( i=0;i<m;i++)
{
if(a.A[i]!=b.A[i])
break;
}
if(i==m)
{
//botj were equal
if(m==strlen(a.A))
{
//a has ended
t=1;
}
else
{
//b has ended
k=1;
}
}
else
{
//someone if larger than other
if(a.A[i]>b.A[i])
{
//a is larger
k=1;
}
else
{
//b is larger
t=1;
}
}
return (k<t);*/
return (a.c<b.c);
}

int main()
{
//char arr[]=['R','G','B','W'];
int i,j,k;
int b[100];
char a[55];
int test;
scanf("%d",&test);
while(test--)
{
scanf("%s",&a);
b['R']=0;
b['G']=0;
b['B']=0;
b['W']=0;
int l=strlen(a);
for(i=0;i<l;i++)
{
b[a[i]]++;
}
bool q=1,w=1,e=1,r=1;
if(b['R']%2!=0)q=0;
if(b['G']%2!=0)w=0;
if(b['B']%2!=0)e=0;
if(b['W']%2!=0)r=0;
if((q*w*e*r)==1)
printf("YES\n");
else printf("NO\n");
}
}





