#include<iostream>
#include<cstdlib>
#include<vector>
#include<climits>
#include<cctype>
#include<map>
#include<list>
#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<cmath>
#include<queue>
#include<fstream>
#include<sstream>
#include<set>
#include<iomanip>
#include<bitset>
#include<ctime>
#define L long long int
#define LD long double
#define pi 3.141592653589793238462643383
#define M 1000000007

using namespace std;


int main()
{
    int t=100,i,j,in,ma,mi,en,mid,h,l,n;
    L ans;
    cin>>t;
    while(t--)
    {
            cin>>n>>l>>h;
            int a[n];
            
            for(i=0;i<n;i++)
            cin>>a[i];
            if(n==1||n==2)
            {
                    cout<<"0\n";
                    continue;
            }
            
            sort(a,a+n);
            //r(i=0;i<n;i++)
            //cout<<a[i]
            ans=0;
            for(i=0;i<n-2;i++)
            {
            //cout<<"a";                            
                            for(j=i+1;j<n-1;j++)
                            {
                                              //cout<<"b";
                                              //if(a[i]+a[j]>=h)
                                              //break;
                                              if(a[i]+a[j]+a[j+1]>h)
                                              break;
                                              if(a[i]+a[j]+a[n-1]<l)
                                              continue;
                                              //rem=h-a[i]-a[j];
                                              
                                              //if(j+1==n-1)
                                              //{
                                                          
                                              in=j+1;
                                              en=n-1;
                                              mi=INT_MAX;
                                              while(in<=en)
                                              {
                                                          mid=(in+en)/2;
                                                          //cout<<mid<<"\n";
                                                          if(a[i]+a[j]+a[mid]>=l&&a[i]+a[j]+a[mid]<=h)
                                                          {
                                                                                                      mi=min(mi,mid);
                                                                                                      en=mid-1;
                                                          }
                                                          else if(a[i]+a[j]+a[mid]>h)
                                                          en=mid-1;
                                                          else
                                                          in=mid+1;
                                                          //ut<<"h";
                                              }
                                              in=j+1;
                                              en=n-1;
                                              ma=INT_MIN;
                                              while(in<=en)
                                              {
                                                          mid=(in+en)/2;

                                                          //cout<<mid<<"\n";
                                                          if(a[i]+a[j]+a[mid]>=l&&a[i]+a[j]+a[mid]<=h)
                                                          {
                                                                                                      ma=max(ma,mid);
                                                                                                      in=mid+1;
                                                          }
                                                          else if(a[i]+a[j]+a[mid]>h)
                                                          en=mid-1;
                                                          else 
                                                          in=mid+1;
                                              }
                                              if(mi==INT_MAX||ma==INT_MIN)
                                              { }
                                              else
                                              ans+=(ma-mi+1);
                            }
            }
            
            cout<<ans<<"\n";
              
              
              
    }
    return 0;
}
