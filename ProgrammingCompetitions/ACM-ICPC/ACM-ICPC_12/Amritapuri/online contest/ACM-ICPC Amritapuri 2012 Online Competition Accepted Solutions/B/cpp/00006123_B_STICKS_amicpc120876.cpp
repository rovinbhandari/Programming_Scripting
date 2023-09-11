#include<stdio.h>
#define up 50002

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int n,m,count,i;
        long long int total,max=0,x,y,z,l[up];
        scanf("%d %d",&n,&m);
        for(i=0;i<n;i++)
        {scanf("%lld",&l[i]);}
        
        for(i=0;i<m;i++)
        {scanf("%lld %lld %lld",&x,&y,&z);
        total=(long long int)(x*x + y*y + z*z);
        if(total>max){max=total;}
        }
        
        count=0;
        for(i=0;i<n;i++)
        {total=(long long int)(l[i]*l[i]);
         if(total<=max){count++;}
        }
        
        printf("%d\n",count);
                        
    }    
    
return 0;    
}
