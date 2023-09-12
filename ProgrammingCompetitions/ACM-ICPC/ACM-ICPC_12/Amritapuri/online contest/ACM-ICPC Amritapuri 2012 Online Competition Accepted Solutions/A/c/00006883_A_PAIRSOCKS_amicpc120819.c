#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main()
{
    int T=0;
    scanf("%d",&T);
    while(T--)
    {

        int i=0,RC=0,GC=0,BC=0,WC=0,ans;
        char arr[55],a;
        scanf("%s",arr);
        while((a=arr[i])!='\0')
        {
            switch(a)
            {

                case 'R':
                ans=RC=(RC+1)%2;
                break;

                case 'B':
                ans=BC=(BC+1)%2;
                break;

                case 'G':
                ans=GC=(GC+1)%2;
                break;

                case 'W':
                ans=WC=(WC+1)%2;
                break;

            }
            i++;

        }

        if(RC==0 && BC==0 && GC==0 && WC==0)
        printf("YES\n");

        else
        printf("NO\n");

    }
    return 0;
}
