#include<stdio.h>
#include<string.h>
int main()
{
    int t,i,r,b,g,w;
    char st[100];
    scanf("%d",&t);
    while(t--)
    {
        memset(st,0,sizeof(st));
        r=b=g=w=1;
        scanf("%s",st);
        for(i=0;st[i];i++)
        {
            switch(st[i])
            {
                case 'R':r=1-r;break;
                case 'B':b=1-b;break;
                case 'G':g=1-g;break;
				case 'W':w=1-w;break;
            }
        }
        if(r&&b&&w&&g)printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}