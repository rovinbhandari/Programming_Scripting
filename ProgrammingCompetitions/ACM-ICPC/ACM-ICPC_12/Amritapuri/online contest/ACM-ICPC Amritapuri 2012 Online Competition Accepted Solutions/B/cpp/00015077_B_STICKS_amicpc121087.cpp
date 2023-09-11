#include<stdio.h>
#include<cmath>

int main()
{
    int T,i,j,sticks;
    int m,n,p;
    scanf("%d",&T);
    while(T>0)
    {
        scanf("%d %d",&m,&n);
        int l[m];
        long unsigned int a,b,c,max=0;
        long unsigned int d;
        for(i=0;i<m;i++)
        {
            scanf("%d",&l[i]);
        }
        for(j=0;j<n;j++)
        {
            scanf("%lu %lu %lu",&a,&b,&c);
            d=sqrt((a*a)+(b*b)+(c*c));
            if (d>max)
            {
                max=d;
            }
        }

        p=0;
        for(sticks=0;sticks<m;sticks++)
        {
            if(l[sticks]<=max)
            {
                p=p+1;
            }
        }
        printf("%d\n",p);
        getchar();

    T=T-1;
}
    return 0;
}
