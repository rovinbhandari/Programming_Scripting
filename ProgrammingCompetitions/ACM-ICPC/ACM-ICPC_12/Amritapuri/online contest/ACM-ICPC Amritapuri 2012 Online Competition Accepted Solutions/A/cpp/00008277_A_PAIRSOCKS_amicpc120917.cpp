#include <cstdio>

char str[52];

int main()
{
    int T, i, r, g, b, w;
    scanf("%d", &T);
    while (T--)
    {
        r = g = b = w = 0;
        scanf("%s", str);
        for(i = 0; str[i]; i++)
        {
            if (str[i] == 'R') r++;
            else if (str[i] == 'G') g++;
            else if (str[i] == 'B') b++;
            else if (str[i] == 'W') w++;
        }
        if (r % 2 || g % 2 || b % 2 || w % 2)
            printf("NO\n");
        else
            printf("YES\n");
    }
    return 0;
}