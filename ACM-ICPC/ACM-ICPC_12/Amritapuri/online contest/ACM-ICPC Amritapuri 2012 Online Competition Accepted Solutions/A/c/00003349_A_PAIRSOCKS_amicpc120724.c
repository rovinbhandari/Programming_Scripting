#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#define lli long long int
lli i,j,k, diff;

inline lli max(lli value1, lli value2){return (value1 > value2 ? value1 : value2);}
inline lli findmod(lli num, lli mod) { lli ans=num%mod; return ( ans >= 0 ? ans : mod+ans ); }
#define printl printf("\n");

#define foi(k,n)   for( i=k; i<n; i=i++)
#define rfoi(n,k)   for( i=n; i>=k; i=i--)
#define foj(k,n)   for( j=k; j<n; j++)
#define rfoj(n,k)   for( j=n; j>=k; j--)

#define foid(k,n,diff)   for( i=k; i<n; i=i+diff)
#define rfoid(n,k,diff)   for( i=n; i>=k; i=i-diff)

#define mod 1000000007

long long int modularexp(long long int base, long long int power){
    long long int i=0,k, temp=power, c=0, d=1, powarr[1000];
    while(temp)  powarr[i] = temp%2,  temp /= 2, i+=1;
    k = i;
    foi(0,k){
        d = (d*d)%mod;
        if(powarr[k-i-1]==1)
            d = (d*base)%mod ;
    }
return d;
}

int main(){
    lli r,g,b,w, n,num,len,  index , power,base,  curr,prev,  temp,temp1,temp2,  sum,ans, p,q;
    char ch[51];
    scanf("%lld",&n);
    foj(0,n)
    {
        r=g=b=w=0;
        scanf("%s",ch);
        len=strlen(ch);
        if(len%2 == 1)
            printf("NO\n");
        else
        {
            foi(0,len)
            {
                if(ch[i]=='R')
                    r++;
                else if(ch[i]=='B')
                    b++;
                else if(ch[i]=='G')
                    g++;
                else if(ch[i]=='W')
                    w++;
            }
            //printf("%lld %lld %lld %lld",r,g,b,w);
            if(!(r%2) && !(b%2) && !(g%2) && !(w%2))
                printf("YES\n");
            else
                printf("NO\n");
        }

    }
return 0;
}
