#include <stdio.h>

int main()
{
    long long count,s,b,n[50001],m[50001],len,bre,hei,i,j,lar,num=0;
    scanf("%lld",&count);
    for(i=0;i<count;i++)
    {
        num=0;
        scanf("%lld",&s);
        scanf("%lld",&b);
        for(j=0;j<s;j++)
        scanf("%lld",&n[j]);
        for(j=0;j<b;j++)
        {
            scanf("%lld %lld %lld",&len,&bre,&hei);
            m[j]=((len*len)+(bre*bre)+(hei*hei));
        }
        lar=m[0];
        for(j=0;j<b;j++)
        {
            if(m[j]>lar)
            lar=m[j];
        }
       // printf("(lar)=%lld--",lar);
        for(j=0;j<s;j++)
        {
        if((n[j]*n[j])<=lar)
        {
        num++;
       // printf("(%lld)\n",n[j]);
        }
        }
        printf("%lld\n",num);
    }
    return 0;
}
