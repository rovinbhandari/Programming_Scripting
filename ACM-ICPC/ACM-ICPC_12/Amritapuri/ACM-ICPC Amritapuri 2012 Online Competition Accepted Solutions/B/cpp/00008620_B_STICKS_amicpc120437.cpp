#include<iostream>
#include<math.h>
#include<cstdio>
using namespace std;
/*
int pow(int a,int b)
{
 int t;
 t=a;
 for(i=0;i<b-1;i++)
 t=t*a;   
 
 return t;
 
}
*/
int main()

{
    long long int t,cnt,i,j,n,m,p,q1,q2,q3;
     cin>>t;
    double max1;
    while(t--)
    {
     cnt=0;    
     cin>>n>>m;
     int a[n];
     long long int b[m][3];
     double d[m];
     for(i=0;i<n;i++)
     cin>>a[i];
     
     for(i=0;i<m;i++)
     {
     cin>>b[i][0]>>b[i][1]>>b[i][2];
     q1=b[i][0];
     q2=b[i][1];
     q3=b[i][2];
     p=(q1*q1)+(q2*q2)+(q3*q3);
    
     d[i]=pow((long double)p,0.5);
     }
     
     
     max1=d[0];
     for(i=1;i<m;i++)
     {
     //max1=d[0];

      if(d[i]>max1)
       max1=d[i];
      }
      
      for(i=0;i<n;i++)
      {
      if(a[i]<=max1)
      cnt++;
      }
      
      printf("%lld\n",cnt);
      //cout<<endl;
      
      }
      
       
}
     
     
