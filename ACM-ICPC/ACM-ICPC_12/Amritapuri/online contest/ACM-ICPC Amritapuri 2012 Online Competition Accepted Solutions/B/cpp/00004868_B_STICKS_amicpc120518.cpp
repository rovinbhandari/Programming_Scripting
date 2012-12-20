#include<stdio.h>
 
long long int l[50000],a[50000],b[50000],c[50000],diag[50000];
 
int main(void)
{
long long int i,x,m,n,max=0,count=0;
scanf
("%lld",&x);
while(x)
{       x-=1;
    max=0;
    count=0;
    scanf
("%lld%lld",&n,&m);
    for(i=0;i<n;i++)
    {scanf
("%lld",&l[i]);
    l[i]=l[i]*l[i];
    }
    for(i=0;i<m;i++)
    {
    scanf
("%lld%lld%lld",&a[i],&b[i],&c[i]);
    diag[i]=a[i]*a[i]+b[i]*b[i]+c[i]*c[i];
    
    if(diag[i]>max)
    max=diag[i];
    }       
        for(i=0;i<n;i++)
        if(l[i]<=max)
        count++;
    printf
("%lld\n",count);
    
    
        
    
}
return 0;
}