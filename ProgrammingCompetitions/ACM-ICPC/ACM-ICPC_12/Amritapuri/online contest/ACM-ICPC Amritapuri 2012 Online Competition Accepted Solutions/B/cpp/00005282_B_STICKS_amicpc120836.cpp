#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    long long int max_diagonal;
    int T;
    scanf("%d",&T);
    int n,m,ptr,ans;
    long long int length,temp,a,b,c;
    long long int my_length[50001];
    
    while(T-->0)
    {
        scanf("%d %d",&n,&m);
        ptr=0;
        ans=0;
        
        while(n-->0)
        {
            scanf("%lld",&length);
            length=length*length;
            my_length[ptr++]=length;
        }
        scanf("%lld %lld %lld",&a,&b,&c);
        max_diagonal=(long long int)a*a;
        max_diagonal+=(long long int)b*b;
        max_diagonal+=(long long int)c*c;
        m--;
        //printf("here2");
        
        while(m-->0)
        {
            scanf("%lld %lld %lld",&a,&b,&c);
            temp=(long long int)a*a;
            temp+=(long long int)b*b;
            temp+=(long long int)c*c;
            if(max_diagonal < temp)
                max_diagonal=temp;
        }
        for(int i=0;i<ptr;i++)
        {
            if(max_diagonal >= my_length[i])
                ans++;
        }
        printf("%d\n",ans);
        
        //printf("here1");
    }
    
    return 0;
}