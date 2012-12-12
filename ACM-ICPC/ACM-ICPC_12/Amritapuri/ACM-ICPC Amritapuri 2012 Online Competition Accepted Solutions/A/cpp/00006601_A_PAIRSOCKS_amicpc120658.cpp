#include <stdio.h>
#include <string.h>
int main()
{

    char str[100];
    long int T;
    int cn1,cn2,cn3,cn4,i;
    scanf("%ld",&T);
    while(T--)
    {
        cn1=0;cn2=0;cn3=0;cn4=0;
        scanf("%s",str);
        for(i=0;i<strlen(str);i++)
        {
           if(str[i]=='R')
           cn1++;
           if(str[i]=='G')
           cn2++;
           if(str[i]=='B')
           cn3++;
           if(str[i]=='W')
           cn4++;
        }
        if((cn1%2==0)&&(cn2%2==0)&&(cn3%2==0)&&(cn4%2==0))
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}
