#include<iostream>
#include <cstdio>
#include <climits>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cmath>
#include <vector>
#include <stack>
#include <set>
#include <map>
#include <deque>
#include <string>

#define all(i,n) for(i = 0; i < (n); i++)
#define SET(p) memset(p,-1,sizeof(p))
#define CLR(p) memset(p,0,sizeof(p))
#define maX(a,b) ((a)>(b)?(a):(b))
#define miN(a,b) ((a)<(b)?(a):(b))
#define S(n) scanf("%d",&n)
#define P(n) printf("%d\n",n)
#define Sl(n) scanf("%lld",&n)
#define Pl(n) printf("%lld\n",n)
#define Sf(n) scanf("%lf",&n)
#define Ss(n) scanf("%s",n)
#define LL long long
#define ULL unsigned long long
#define pb push_back
#define mod 1000000007
using namespace std;
int  b[200005],a[2000];
void merge(int  *a,int low,int mid ,int high);
void divide(int  *a,int low,int high)
{
     int mid;
      if(low<high)
     {   mid=(low+high)/2;
                   divide(a,low,mid);
                   divide(a,mid+1,high);
                   merge(a,low,mid,high);
                   }

}
void merge(int  *a,int low,int mid ,int high)
{ int i=low,j=mid+1,index=low;

   while(i<=mid && j<=high)
   { if(a[i]<=a[j])
      b[index++]=a[i++];
     else
      {b[index++]=a[j++];
      }
      }
    if(i>mid)
    { while(j<=high)
       b[index++]=a[j++];
       }
    else
    {while(i<=mid)
    b[index++]=a[i++];}


   for(int k=low;k<=high;k++)
    a[k]=b[k];
    return;
}
int binarySearch1(int num,int x)
{
    int low=0,high=x;
                        int mid=(low+high)/2;
                        while(low<high && a[mid]!=num)
                        {
                                       if(a[mid]<num)
                                       low=mid+1;
                                       else
                                       high=mid;
                                       mid=(low+high)/2;
                                       }
                         if(a[mid]!=num)
                        {
                            while(a[mid]>num&&mid>=0)
                            mid--;
                            return mid;
                        }
                          else
                          {

                               while(a[mid]==num&&mid<=x)
                               mid++;

                           return (mid-1);
                          }

}
int binarySearch2(int num,int x)
{
    int low=0,high=x;
                        int mid=(low+high)/2;
                        while(low<high && a[mid]!=num)
                        {
                                       if(a[mid]<num)
                                       low=mid+1;
                                       else
                                       high=mid;
                                       mid=(low+high)/2;
                                       }
                         if(a[mid]!=num)
                         return low;
                          else
                          {

                               while(a[mid]==num&&mid>=0)
                               mid--;

                           return (mid+1);
                          }
}

int main()
{
   int t,n,l,h,rem,upper,lower,i,j,range;
   long long count;
   S(t);
   while(t--)
   {
       S(n);
       S(l);
       S(h);
       all(i,n)
       S(a[i]);
       divide(a,0,n-1);
       //all(i,n)
       //cout<<a[i];
       count=0;
       for(i=0;i<n;i++)
       {
           for(j=i+1;j<n;j++)
           {
               rem=h-a[i]-a[j];

               if(rem>=0)
               upper=binarySearch1(rem,n-1);

               else
               upper=-1;
            //   P(upper);
               rem=l-a[i]-a[j];
               if(rem>0)
               lower=binarySearch2(rem,n-1);
               else
               lower=0;
               if(lower>n-1)
               lower=0;
               lower=maX(lower,j+1);

               //printf("%d %d %d %d\n",i,j,lower,upper);
               if(upper>=lower&&upper<=n-1)
               { lower=maX(lower,j+1);
                 range=upper-lower+1;
                count+=range;

               // printf("%d %d %d %d\n",i,j,upper,lower);
               }


           }
       }
       printf("%lld\n",count);
   }
return 0;
}


