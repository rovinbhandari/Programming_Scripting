#include<stdio.h>
#include<string.h>
int main()
{
    int i,j,n,r,g,w,b;
    scanf("%d",&n);
    char a[60];
    for (i=1;i<=n;i++)
    {
        scanf("%s",&a);
        r=0;
        g=0;
        b=0;
        w=0;
        for (j=0;j<=strlen(a)-1;j++)
        {
            if (a[j]=='W')
            w++;
            else if (a[j]=='R')
            r++;
            else if (a[j]=='G')
            g++;
            else if (a[j]=='B')
            b++;
            }
         if (w%2==0 && r%2==0 && b%2==0 && g%2==0)
         printf("YES\n");
         else
         printf("NO\n");
         }
         
                  
return 0;
}
