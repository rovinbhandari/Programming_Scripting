#include<stdio.h>
int swap(int *i, int *j)
{
    int temp;
    temp=*i;
    *i=*j;
    *j=temp;
}
int main()
{
    int i,j,k,l,m,n,a[1001],t,count,k1,j1;
    scanf("%d",&t);
    while(t--)
    {
                count=0;
        scanf("%d%d%d",&n,&l,&m);
        //printf("%d %d %d",n,l,m);
        for(i=0;i<n;i++)
        {
        scanf("%d",&a[i]);
        //printf("%d",a[i]);
        }
        for(i=0;i<n;i++)
        {
            for(j=i+1;j<n;j++)
            {
                if(a[i]>a[j])
                swap(&a[i],&a[j]);
            }
        }
        for(i=0;i<n-2;i++)
        {
            j=i+1;
            k=n-1;
        while(j<k)
        {
            if(l>a[i]+a[j]+a[k])
               j++;
            else if(a[i]+a[j]+a[k]>m)
            k--;
            else if((l<=a[i]+a[j]+a[k])&&(m>=a[i]+a[j]+a[k]))
            {
                for(j1=j;j1<=k;j1++)
                {
                    for(k1=j1+1;k1<=k;k1++)
                    {
                       // printf("hii\n");
                        if((l<=a[i]+a[j1]+a[k1])&&(m>=a[i]+a[j1]+a[k1]))
                        count++;
                    }
                }
                break;
            }


        }

        }
        printf("%d\n",count);
    }

    return 0;
}
