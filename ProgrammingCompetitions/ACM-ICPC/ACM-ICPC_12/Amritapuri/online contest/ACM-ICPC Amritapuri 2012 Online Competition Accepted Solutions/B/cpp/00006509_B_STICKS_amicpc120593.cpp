#include<iostream>
#include<stdio.h>
#include<math.h>

struct box {
    unsigned long long l,b,h;
};
using namespace std;

int main()
{
    int T,N,M;
    int i,j;
    unsigned long long stick[50001],len[50001],maxlen, maxind;
   // freopen("in","r",stdin);
    box b[50001];
    scanf("%d",&T);
    int count;
    while (T--)
    {
        scanf("%d%d",&N,&M);
        for (i=0;i<N;i++)
            scanf("%llu",&stick[i]);
        count = 0;
        maxlen=0;
        maxind=0;
        for (i=0;i<M;i++)
        {
            scanf("%llu%llu%llu",&b[i].l,&b[i].b,&b[i].h);
            len[i]=sqrt((b[i].l*b[i].l)+(b[i].b*b[i].b)+(b[i].h*b[i].h));
            if (len[i]>maxlen)
            {
                maxlen=len[i];
                maxind=i;
            }
            
        }
        for (i=0;i<N;i++)
        {
            if (stick[i]<=len[maxind])
                count++;
        }
        printf("%d\n",count);
    }
}
