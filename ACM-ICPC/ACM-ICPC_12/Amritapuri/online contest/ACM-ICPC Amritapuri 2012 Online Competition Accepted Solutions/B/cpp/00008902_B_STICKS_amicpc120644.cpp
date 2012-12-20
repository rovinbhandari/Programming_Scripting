#include<iostream>
#include<math.h>
#include<cstdio>

using namespace std;
int maxim(double b[],int m)
{
    int i;
    int ma=b[0];
    for(i=0;i<m;i++)
        if(ma<b[i])
            ma=b[i];
    return ma;
}

int main()
{
    int n,m,l[50000];
    long a[50000],b[50000],c[50000];
    double dee[50000];
    double abc;
    int t;
    int count;
    int i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        count=0;
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
            scanf("%d",&l[i]);
        for(i=0;i<m;i++)
        {
            scanf("%ld",&a[i]);
            scanf("%ld",&b[i]);
            scanf("%ld",&c[i]);
        }
        for(i=0;i<m;i++)
        {
            dee[i]=double(a[i]*a[i]+b[i]*b[i]+c[i]*c[i]);
            dee[i]=sqrt(dee[i]);
            //cout<<diag<<endl;
        }
        
        abc=maxim(dee,m);
        for(i=0;i<n;i++)
            if(l[i]<=abc)
                count++;
                
        printf("%d\n",count);
        
        
    }
}
