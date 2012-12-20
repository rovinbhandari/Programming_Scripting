#include<stdio.h>
#include<string.h>
int main()
{
    int t;char a[100];
    scanf("%d",&t);
    while(t--)
    {
        scanf("%s",a);
        int r=0,b=0,g=0,w=0,i=0;
        for(i=0;i<strlen(a);i++)
        {
            switch(a[i])
            {
                case 'R':r++;break;
                case 'G':g++;break;
                case 'B':b++;break;
                case 'W':w++;break;
            }

        }
        if(r&1 || g&1 || b&1 || w&1 )
            printf("NO\n");
            else
            printf("YES\n");
    }
    return 0;
}

