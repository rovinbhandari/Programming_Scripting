#include<stdio.h>

int main()
{
    int z,t;
    scanf("%d",&t);
    for(z=0;z<t;z++)
    {
        char s[100];
        scanf("%s",s);
        {

            int a[4]={0};
            int i;
            for(i=0;s[i]!=0;i++)
            {
                if(s[i]=='R')
                    a[0]++;
                if(s[i]=='G')
                    a[1]++;
                if(s[i]=='B')
                    a[2]++;
                if(s[i]=='W')
                    a[3]++;

            }
            if(a[0]%2==0 && a[1]%2==0 && a[2]%2==0 && a[3]%2==0 )
                printf("YES\n");
            else
                printf("NO\n");
        }
    }
    return 0;
}
