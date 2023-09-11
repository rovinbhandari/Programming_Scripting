#include<iostream>
#include<math.h>
using namespace std;
int main()
{
int T,i;
long long int N,M,j,k, count;
double L[50001];
double A[50001],B[50001],C[50001];
double D,finalD;
cin>>T;
for(i=0;i<T;i++)
{
D=0,finalD=0;
count=0;
cin>>N;
cin>>M;
for(j=0;j<N;j++)
cin>>L[j];
for(k=0;k<M;k++)
{
cin>>A[k]>>B[k]>>C[k];
D=sqrt((A[k]*A[k])+(B[k]*B[k])+(C[k]*C[k]));
if(D>finalD)
finalD=D;
}
for(j=0;j<N;j++)
{
if(L[j]<=finalD)
count++;
}
cout<<count<<"\n";
}
return 0;
}