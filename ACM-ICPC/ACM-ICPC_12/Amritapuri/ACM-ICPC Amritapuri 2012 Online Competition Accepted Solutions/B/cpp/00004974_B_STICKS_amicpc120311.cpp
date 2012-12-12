#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t,n,m,i;
    long long int l[50000],a[50000],b[50000],c[50000],temp;
    scanf("%d", &t);
    while(t--)
    {
        int maxi=-1;
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%ld", &l[i]);
        }
        for(i=0;i<m;i++)
        {
            scanf("%ld %ld %ld",&a[i],&b[i],&c[i]);
            temp=sqrt(a[i]*a[i] + b[i]*b[i] + c[i]*c[i]);
            if(temp>maxi)
                maxi=temp;
        }
    //    printf("%d\n",maxi);
        int count=0;
        for(i=0;i<n;i++)
        {
            if(l[i]<=maxi)
            {
                count++;
      //          printf("%d\n",l[i]);
            }

        }
        printf("%d\n",count);
    }
    return 0;
}
