#include<stdio.h>
#include<map>
#include<stdlib.h>
#include<algorithm>
using namespace std;
int main()
{
    int t,i,j,n,l,h,*a,count,p,q,g,f;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {

        scanf("%d %d %d",&n,&l,&h);
        count=0;
        a=(int *)malloc(n*sizeof(int));
        for(j=0;j<n;j++)
        scanf("%d",&a[j]);
        sort(a,a+n);
        for (j= 0; j < n - 2; j++)
      {


        p = j + 1; // index of the first element in the remaining elements
        q = n-1; // index of the last element
        while (p < q)
        {
            if( (a[j] + a[p] + a[q]) <=h && (a[j] + a[p] + a[q])>=l)
            {count++;
             g=p;
             f=q;
             q--;
             while(p<q)
             {
                 if((a[j]+a[p]+a[q]<=h) && (a[j] + a[p] + a[q])>=l)
                 count++;
                 q--;
             }
             q=f;
             p++;
             while(p<q)
             {
                 if(a[j]+a[p]+a[q]<=h && (a[j] + a[p] + a[q])>=l)
                 count++;
                 p++;
             }
             p=g;
             q=f;
             p++;
             q--;
            }
            else if (a[j] + a[p] + a[q] < l)
                p++;
            else
                q--;
        }
      }
        printf("%d\n",count);
        free(a);

    }
    return 0;

}
