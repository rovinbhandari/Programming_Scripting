#include<stdio.h>
#include<stdlib.h>

int main()
{
    unsigned long long int t,n,m,j,k;
    unsigned long long int i,*diag,*sticks;
    unsigned long long int l,b,h,ct,max;
    
    scanf("%llu",&t);
    for(i=0;i<t;i++)
    {
        scanf("%llu",&n);
        scanf("%llu",&m);
        max=ct=0;
        sticks = (unsigned long long int *)malloc(sizeof(unsigned long long int)*n);
        diag = (unsigned long long int *)malloc(sizeof(unsigned long long int)*m);
        for(j=0;j<n;j++)
            scanf("%llu",&sticks[j]);
        
        for(j=0;j<m;j++)
        {
            scanf("%llu %llu %llu",&l,&b,&h);
            diag[j]=(l*l)+(b*b)+(h*h);
            if(diag[j]>max)
                max=diag[j];
        }
        
        for(j=0;j<n;j++)
            if((sticks[j]*sticks[j])<=max)
                ct++;
        
        printf("%llu\n",ct);
        
        free(sticks);
        free(diag);
    }

    return 0;
}
