#include<iostream>
#include<math.h>
#include<cstdio>

using namespace std;
int maxi(double a[],int n)
{
    int i;
    int max=a[0];
    for(i=0;i<n;i++)
        if(max<a[i])
            max=a[i];
    return max;
}

/*int mini(int a,int b,int c)
{
    int temp=a<b?a:b;
    temp=temp<c?temp:c;
    
    return temp;
    
}*/

int main()
{
    int n,m,l[50000];
    long a[50000],b[50000],c[50000];
    double diag[50000];
    double max;
    int t;
    int num;
    int i,j,k;
    scanf("%d",&t);
    while(t--)
    {
        num=0;
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
            diag[i]=double(a[i]*a[i]+b[i]*b[i]+c[i]*c[i]);
            diag[i]=sqrt(diag[i]);
            //cout<<diag<<endl;
        }
        
        max=maxi(diag,m);
        for(i=0;i<n;i++)
            if(l[i]<=max)
                num++;
                
        printf("%d\n",num);
        
        
    }
}
