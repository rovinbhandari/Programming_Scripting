#include<stdio.h>

int main()
{
    int i,j,k,t,n,l,h,a[1000],cnt;
    scanf("%d",&t);
    while(t--)
    {
        scanf("%d%d%d",&n,&l,&h);
        cnt = 0;
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        quick_sort(a, 0, n-1);
        for(i=0;i<n-2;i++)
        {
            for(j=i+1;j<n-1;j++)
            {
                for(k=j+1;a[i]+a[j]+a[k]<=h;k++)
                {
                    if(a[i]+a[j]+a[k]>=l)
                        cnt++;
                }
            }
        }
        printf("%d\n",cnt);
    }
    return 0;
}

int quick_sort(int *p,int l,int h)
{
    int i,j,pivot,t;
    if(l<h)
    {
        partition(p,l,h);
        pivot=p[l];
        i=l+1;
        j=l+1;
        while(i<=h)
        {
            if(p[i]<pivot)
            {
                t=p[i];
                p[i]=p[j];
                p[j]=t;
                j++;
            }
            i++;
        }
        p[l]=p[j-1];
        p[j-1]=pivot;
        quick_sort(p,l,j-2);
        quick_sort(p,j,h);
    }
    return 0;
}

int partition(int *p,int l,int h)
{
    int t,m=(l+h)/2;
    if((p[l]<p[m]&&p[m]<p[h])||(p[h]<p[m]&&p[m]<p[l]))
    {
        t=p[l];
        p[l]=p[m];
        p[m]=t;
    }
    else if((p[l]<p[h]&&p[h]<p[m])||(p[m]<p[h]&&p[h]<p[l]))
    {
        t=p[l];
        p[l]=p[h];
        p[h]=t;
    }
    return 0;
}
