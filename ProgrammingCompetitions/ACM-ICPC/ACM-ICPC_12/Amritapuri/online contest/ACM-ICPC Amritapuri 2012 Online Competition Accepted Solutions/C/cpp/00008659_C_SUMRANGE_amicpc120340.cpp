#include<cstdio>
#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
                int ll,l,h;
                scanf("%d %d %d",&ll,&l,&h);
                int arr[ll];
                int n=0;
                for(int i=0;i<ll;i++)
                {
                        int p;
                        scanf("%d",&p);
                        if(p<h-2)
                        {    arr[n]=p;
                             n++;
                        }
                }
                sort(arr,arr+n);
                long long int count=0;
                for(int i=0;i<n-2;i++)
                {
                       for(int j=i+1;j<n-1;j++)
                       {
                         if((arr[i]+arr[j]>h-arr[j+1])||(arr[i]+arr[j]<l-arr[n-1]))
                         {
                            ;
                         }
                            else
                            {     int k=n-1;
                                  int y=j+1;

                                 while((arr[i]+arr[j]+arr[k]>h)&&(k>j))
                                 {          k--;
                                      //  (arr[i] + arr[j] + arr[k] < l ) ? j++ : k--;
                                  }
                                  while((arr[i]+arr[j]+arr[y]<l)&&(y<n))
                                 {          y++;
                                      //  (arr[i] + arr[j] + arr[k] < l ) ? j++ : k--;
                                  }
                                  count+=k-y+1;
                          }
                       }
                }
                printf("%lld\n",count);
        }

        return 0;
}
