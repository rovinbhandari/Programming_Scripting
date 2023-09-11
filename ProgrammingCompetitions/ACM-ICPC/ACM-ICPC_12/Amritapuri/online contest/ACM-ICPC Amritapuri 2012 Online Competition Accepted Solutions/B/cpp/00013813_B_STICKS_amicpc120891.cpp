#include<stdio.h>
#include<math.h>
long int l[51000];
double b[51000];
int main()
{
    long int i,j,k,z,m,n,p,c1,c2,c3,t;
    double max;
    scanf("%ld",&t);
    while(t--)
    {
        c1=0;c2=0;c3=0;
        max=0;
        scanf("%ld %ld",&n,&m);
        for(i=0;i<n;i++)
        {
            scanf("%ld",&l[i]);
        }
        for(i=0;i<m;i++)
        {
            scanf("%ld %ld %ld",&j,&k,&z);
            b[i]=sqrt((double)(j*j+k*k+z*z));
            if(b[i]>max)
                max=b[i];
        }
        for(i=0;i<m;i++)
        {
            if(b[i]==max)
                c1++;
        }
        for(i=0;i<n;i++)
        {
            if(l[i]<max)
                c2++;
        }
        for(i=0;i<n;i++)
        {
            if(l[i]==max)
                c3++;
        }
        if(c3<=4*c1)
            printf("%ld\n",c2+c3);
        else
            printf("%ld\n",c2+4*c1);
    }
    return 0;
}
