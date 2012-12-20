#include<iostream>
#include<cstdio>
#include<string.h>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
int i,j,k,n,t,m;
scanf("%d",&t);
while(t--)
{
          scanf("%d%d",&n,&m);
          double a[n];
          double b[m][3];
          double c[m];
          for(i=0;i<n;i++)
          cin>>a[i];
          sort(a,a+n);//for(i=0;i<n;i++)cout<<a[i]<<"   ";
          for(i=0;i<m;i++)
          {
                          cin>>b[i][0]>>b[i][1]>>b[i][2];
                          sort(b[i],b[i]+3);
                         // for(j=0;j<m;j++)
                          //cout<<b[i][0]<<b[i][1]<<b[i][2]<<"\n";
                          c[i]=pow(((b[i][0]*b[i][0])+(b[i][1]*b[i][1])+(b[i][2]*b[i][2])),0.5);
          }
          sort(c,c+m);
         
          for(i=n-1;i>=0;i--)
         if(a[i]<=c[m-1])
          break;

          cout<<i+1<<"\n";
}
}
          
