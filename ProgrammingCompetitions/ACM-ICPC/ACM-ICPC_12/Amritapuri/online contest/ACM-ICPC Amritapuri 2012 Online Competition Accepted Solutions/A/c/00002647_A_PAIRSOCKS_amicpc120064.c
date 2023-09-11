
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int test=0;
    scanf("%d",&test);
    int i=0;
    for(i=0;i<test;i++)
    {
        char str[51];
        scanf("%s",str);
        int j=0;
        int countR=0;
        int countW=0;
        int countB=0;
        int countG=0;
        for(j=0;j<strlen(str);j++)
        {
            if(str[j]=='R')
                countR++;
            else if(str[j]=='G')
                countG++;
            else if(str[j]=='B')
                countB++;
            else if(str[j]=='W')
                countW++;
        }
        if(countR%2==0 && countW%2==0 && countG%2==0 && countB%2==0)
            printf("YES\n");
        else
            printf("NO\n");
    }
    return 0;
}

            

