#include<stdio.h>
#include<string.h>
void main()
{
    char s[51];
    int T, i, j, len, count[4], n, o[1000];
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        fscanf(stdin, "%s", s);
        len = strlen(s);
        count[0] = count[1] = count[2] = count[3] = 0;
        for(j = 0; j < len; j++)
            switch(s[j])
            {
                case 'R':
                    count[0]++;
                    break;
                case 'G':
                    count[1]++;
                    break;
                case 'B':
                    count[2]++;
                    break;
                case 'W':
                    count[3]++;
                    break;
            }
        for(j = 0; j < 4; j++)
            if(count[j] % 2 != 0)
            {
                o[i] = 0;
                break;
            }
        if(j == 4)
            o[i] = 1;
    }
    for(i = 0; i < n; i++)
        if(o[i])
            printf("YES\n");
        else
            printf("NO\n");
}
