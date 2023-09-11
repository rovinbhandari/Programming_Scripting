#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,k,t,w,n,r,g,b;
    char a[51];
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s",&a);
        r=0;
        g=0;
        b=0;
        w=0;
        n=strlen(a);
        for(j=0;j<n;j++)
        {
            if(a[j]=='R')
                r++;
            else if(a[j]=='G')
                g++;
            else if(a[j]=='W')
                w++;
            else
                b++;

        }
        if((r%2==0)&&(w%2==0)&&(g%2==0)&&(b%2==0))
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
