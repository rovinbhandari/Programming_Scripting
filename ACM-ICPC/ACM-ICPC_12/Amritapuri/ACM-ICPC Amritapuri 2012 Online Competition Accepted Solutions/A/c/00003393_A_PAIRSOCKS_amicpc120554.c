#include<stdio.h>
int main()
{
    int r=1,b=1,w=1,g=1;
    char c[1000];
    int t,i,j;
    scanf("%d",&t);
    for(i=0;i<t;i++)
    {
        scanf("%s",c);
        j=0;
        r=1,b=1,w=1,g=1;
        while(c[j]!='\0')
        {
            if(c[j]=='R')
            {
                if(r==0)
                    r=1;
                else
                    r=0;
            }
            if(c[j]=='G')
            {
                if(g==0)
                    g=1;
                else
                    g=0;
            }
            if(c[j]=='B')
            {
                if(b==0)
                    b=1;
                else
                    b=0;
            }
            if(c[j]=='W')
            {
                if(w==0)
                    w=1;
                else
                    w=0;
            }
             j++;
        }
    if(r==1&&g==1&&w==1&&b==1)
    {
        printf("YES\n");
    }
    else
    {
        printf("NO\n");
    }


}    return 0;

}
