#include<stdio.h>
#include<algorithm>
using namespace std;

int a[1010],n,l,h;
int bs(int i,int j,int sum)
{
    int low,high,mid,b;
    low=j+1;
    high=n-1;

    if(j==n-1)
    return -1;

    while(high>low)
    {
        mid=(low+high)/2;
        if(a[mid]>=sum)
        high=mid;

        else
        low=mid+1;

    }
    if(high==low && a[low]>=sum)
    return low;

    else
    return -1;

}

int bsearch(int i,int j,int sum)
{

    int low,high,mid,b;
    low=j+1;
    high=n-1;

    if(j==n-1)
    return -1;

    while(high>low)
    {
        mid=(low+high+1)/2;
        if(a[mid]<=sum)
        low=mid;
        else
        high=mid-1;

    }
    if(low==high && a[low]<=sum)
    return low;

    else
    return -1;
}

int main()
{
    int i,j,k,count,ans,lindex,hindex;
    scanf("%d",&count);
    while(count!=0)
    {

        ans=0;

       scanf("%d%d%d",&n,&l,&h);
      for(i=0;i<=n-1;i++)
      scanf("%d",&a[i]);

      sort(a,a+n);

      for(i=0;i<=n-2;i++)
      {
          for(j=i+1;j<=n-1;j++)
          {
              lindex=bs(i,j,l-a[i]-a[j]);
              hindex=bsearch(i,j,h-a[i]-a[j]);

             // printf("lindex=%d hindex=%d\n",lindex,hindex);
              if(lindex>=0 && hindex>=0)
              ans=ans+(hindex-lindex)+1;

              if(lindex==-1 || hindex==-1)
              break;

          //  printf("i=%d j=%d lindex=%d hindex=%d ans=%d\n",i,j,lindex,hindex,ans);

          }

      }

       printf("%d\n",ans);

        count--;
    }

    return 0;
}
