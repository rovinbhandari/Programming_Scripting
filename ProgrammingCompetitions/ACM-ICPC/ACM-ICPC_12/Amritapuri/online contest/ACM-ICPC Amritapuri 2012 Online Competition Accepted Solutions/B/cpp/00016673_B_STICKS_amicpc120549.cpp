#include<iostream>
#include<stdio.h>
#include<math.h>
#include<algorithm>
#include<limits.h>
#define min(a,b) (a>b?b:a)
#define max(a,b) (a>b?a:b)
#define abs(a,b) ((a-b)>0?(a-b):(b-a))

using namespace std;
float len[50000];
//int dia[50000];
int main()
{

    int t,i,n,m,j,ans=0,flag=0;
    float l,b,h;
    double sum,maxsum=INT_MIN;
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d",&n);
              scanf("%d",&m);
              for(i=0;i<n;i++)
              {
                              scanf("%f",&len[i]);
                              }
              for(i=0;i<m;i++)
              {
                              scanf("%f",&l);
                              scanf("%f",&b);
                              scanf("%f",&h);
                              sum=l*l+b*b+h*h;
                              sum=sqrt(sum);
                              maxsum=max(maxsum,sum);
                              }
                              for(i=0;i<n;i++)
                              {
                              if(len[i]<=maxsum)                             
                              {
                                  ans++;
                              }
                              }printf("%d\n",ans);
                              ans=0;
                              flag=0;
                              maxsum=INT_MIN;
         }
   
//    system("pause");
    return 0;
    }
