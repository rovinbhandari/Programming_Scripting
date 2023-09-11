#include <stdio.h>
#include <stdlib.h>

int main()
{
    int test,i;
    char color[51];
    int redNo=0,greenNo=0,blueNo=0,whiteNo=0;
    scanf("%d",&test);
    while (test--)
    {
        redNo=greenNo=blueNo=whiteNo=0;
        scanf("%s",color);
        for (i=0;color[i]!='\0';i++)
        {
            switch(color[i])
            {
                case 'R':
                            redNo++;
                            break;
                case 'G':
                            greenNo++;
                            break;
                case 'B':
                            blueNo++;
                            break;
                case 'W':
                            whiteNo++;
                            break;
            }
        }
        if ((redNo%2==0) && (greenNo%2==0) && (blueNo%2==0) && (whiteNo%2==0))
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
