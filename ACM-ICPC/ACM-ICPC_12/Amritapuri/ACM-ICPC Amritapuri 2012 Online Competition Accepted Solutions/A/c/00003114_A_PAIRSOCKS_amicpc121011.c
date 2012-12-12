#include <stdio.h>
#include <string.h>
int test_cases, green, red, blue, white;
int main()
{
    int i,j;
    char line[52];

    scanf("%d\n",&test_cases);

    for (i=0; i<test_cases;i++)
    {
        green=0;
        red=0;
        blue=0;
        white=0;

        fgets(line,sizeof(line),stdin);

        for (j=0;j<strlen(line);j++)
        {
            if (line[j]=='G')
            {
                if (green==0)
                {
                    green=1;
                }
                else
                {
                    green=0;
                }
            }

            else if (line[j]=='W')
            {
                if (white==0)
                {
                    white=1;
                }
                else
                {
                    white=0;
                }
            }

            else if (line[j]=='B')
            {
                if (blue==0)
                {
                    blue=1;
                }
                else
                {
                    blue=0;
                }
            }

            else if (line[j]=='R')
            {
                if (red==0)
                {
                    red=1;
                }
                else
                {
                    red=0;
                }
            }
        }

        if (red==0 && green==0 && white==0 && blue==0)
        {
            printf("YES\n");
        }
        else
        {
            printf("NO\n");
        }
    }

    return 0;
}
