#include<stdio.h>
#include<stdlib.h>
int main(void)
{
    int test=0,i,j,k,a[30]={0},result=0;
    char s[100];
    scanf("%d",&test);
    while(test--)
    {
        scanf("%s",s);
        for(i=0;i<30;i++)a[i]=0;
        for(i=0;s[i]!='\0';i++)
        {
            a[s[i]-65]++;
        }
        for(i=0;i<30;i++)
        {
            if(a[i]%2==0)result=1;
            else
            {
                result=0;break;
            }
        }
        if(result!=0)printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;

}
