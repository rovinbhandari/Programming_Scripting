#include<stdio.h>
#include<string.h>
int main()
{
    int t;
    char string[51];

    scanf("%d",&t);
    while(t--)
    {int count[4]={0};
        int i;
        scanf("%s",string);
        for(i=0;i<strlen(string);i++)
        {
            if(string[i]=='R')
            count[0]++;
            else if(string[i]=='G')
            count[1]++;
            else if(string[i]=='B')
            count[2]++;
            else if(string[i]=='W')
            count[3]++;
        }
        int flag=0;
        for(i=0;i<4;i++)
        {
            if(count[i]%2!=0)
            {
                flag=1;
                break;
            }
        }
        if(flag==0) printf("YES\n");
        else            printf("NO\n");
        }return 0;
        }


