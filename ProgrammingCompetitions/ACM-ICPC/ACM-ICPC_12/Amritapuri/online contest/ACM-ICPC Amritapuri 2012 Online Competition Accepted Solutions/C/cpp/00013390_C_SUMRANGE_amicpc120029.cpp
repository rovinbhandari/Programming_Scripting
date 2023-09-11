#include<iostream>
#include<algorithm>

using namespace std;
int main()
{
    long q,i,j,k,l,l1,h,h1,n,t,count,temp;
    cin>>t;
    int a[1020];
    for(q=0; q<t; q++)
    {
             count=0;
             cin>>n;
             cin>>l;
             cin>>h;
             for(i=0; i<n; i++)
             cin>>a[i];
             sort(a, a+n);
             for(i=0; i<n; i++)
             {
                      for(j=i+1; j<n-i; j++)
                      {
                               if(i!=j)
                               {
                                       temp=a[i]+a[j];
                                       l1=l-temp;
                                       h1=h-temp;
                                       for(k=j+1; k<n; k++)
                                       {
                                                if(a[k]>=l1)
                                                break;
                                       }
                                       for(k; a[k]<=h1; k++)
                                       {
                                              if(i!=k && j!=k)
                                              count++;       
                                       }
                                       
                               }
                      }
             }
             cout<<count<<endl;
             
    }
    //system("PAUSE");
    return 0;
}
