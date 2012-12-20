#include <stdio.h>
#include <string.h>
int main()
{
    char str[50];
    int T,i,l,r,g,b,w;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%s",str);
        l=strlen(str);
        i=0;
        r=0,g=0,b=0,w=0;
        while(i<l)
        {
            switch(str[i])
            {
                case 'R':   r++;
                            break;
                case 'B':   b++;
                            break;
                case 'G':   g++;
                            break;
                case 'W':   w++;
                            break;
            }
            i++;
        }
        if(r%2==0&&w%2==0&&b%2==0&&g%2==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}
