#include<stdio.h>
#include<string.h>

int main()
{
    char pairs[51];
    int i, j, t, r, b, w, g;
    scanf("%d", &t);
    for(i=0; i<t; i++)
    {
        scanf("%s", pairs);
        r=0;
        b=0;
        w=0;
        g=0;
        for(j=0; j<strlen(pairs); j++)
        {
            if(pairs[j]=='R')
                r++;
            else if(pairs[j]=='G')
                g++;
            else if(pairs[j]=='B')
                b++;
            else if(pairs[j]=='W')
                w++;
        }
        if((r%2==0)&&(w%2==0)&&(b%2==0)&&(g%2==0))
            printf("YES\n");
        else
            printf("NO\n");
    }

    return 0;
}
