#include <cassert>
#include <cctype>
#include <cmath>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <list>
#include <deque>
#include <stack>
#include <iterator>
#include <string>
#include <sstream>
#include <iostream>
#include <fstream>
#include <functional>
#include <numeric>
#include <algorithm>
 
using namespace std;
int main()
{
    int t,l,h,n,a[1010];
    scanf("%d",&t);
        while(t--)
{
                scanf("%d%d%d",&n,&l,&h);
                for(int i=0;i<n;i++)
                scanf("%d",&a[i]);
                sort(a,a+n);
                int y=n-1;
                int count1=0,count2=0;
                if(l==1)
                count1=0;
                else
                {
                for(int i=0;i<=n-3;i++)
                {
                for(int j=i+1;j<=n-2;j++)
                {
                        int d=j+1;
                        int u=n-1;
                        int mid;
                       
                        while(d<u)
                        {
                                 //  cout<<"here";
                                  mid=(u+d)/2;
                                  if((a[i]+a[j]+a[mid])>(l-1))
                                  {
                                  u=mid-1;
                                  continue;
                                  }
                                  else if((a[i]+a[j]+a[mid])<=(l-1))
                                  {
                                  d=mid+1;
                                  continue;
                                  }
                        }
                       if((a[i]+a[j]+a[d])>(l-1))
                       d--;
                       
                        count1=count1+d-j;
                }
        }
        }
     //  cout<<count1<<endl;
        for(int i=0;i<=n-3;i++)
                {
                for(int j=i+1;j<=n-2;j++)
                {
                        int d=j+1;
                        int u=n-1;
                        int mid;
                        while(u>d)
                        {
                                 mid=(u+d)/2;
                                  if((a[i]+a[j]+a[mid])>h)
                                  {
                                  u=mid-1;
                                  continue;
                                  }
                                  else if((a[i]+a[j]+a[mid])<=h)
                                  {
                                  d=mid+1;
                                  continue;
                                  }
                        }
                        if((a[i]+a[j]+a[d])>h)
                       d--;
                        count2+=d-j;
                }
        }
       // cout<<count2<<endl;
        printf("%d\n",count2-count1);
  }
//system("pause");
return 0;
}
