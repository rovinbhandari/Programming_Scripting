#include<stdio.h>
#include<math.h>
int main()
{
    unsigned long long int t,n,m,j,i,a,b,c,cnt,d, max;
    unsigned long long no[50000];
    scanf("%llu",&t);
    while(t--)
    {
        cnt=max=0;
        scanf("%llu%llu",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%llu",&no[i]);
        }
        quick_sort(no, 0, n-1);
        for(i=0;i<m;i++)
        {
            scanf("%llu%llu%llu",&a,&b,&c);
            d=(a*a)+(b*b)+(c*c);
//            for(j=0;j<n;j++)
//            {
//                if((no[j]*no[j])<=d && no[j]>0)
//                {
//                    no[j]=0;
//                    cnt++;
//                }
//            }
            if(max<d)
                max = d;
        }
        for(i=n-1;i>=0;i--)
        {
            if(no[i]*no[i]<=max)
            {
                printf("%llu\n",i+1);
                break;
            }
        }
    }
    return 0;
}

int quick_sort(unsigned long long  *p,int l,int h)
{
    int i,j;
    unsigned long long pivot,t;
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

int partition(unsigned long long *p,int l,int h)
{
    int m=(l+h)/2;
    unsigned long long t;
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