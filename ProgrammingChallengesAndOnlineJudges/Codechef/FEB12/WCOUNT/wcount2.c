#include <stdio.h>
#include <string.h>

#define MOD 1000000007

typedef unsigned long long int ulli;

char s[501];

ulli factorial(ulli n)
{
	if(!n)
		return 1;
	ulli f = 1, i = 1;
	while(i <= n)
		f *= i++;
	return f;
}

int main(void)
{
	int t, nr, dr[52], i, j, terms;
	char c;
	ulli result, temp;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%s", s);
		nr = strlen(s);
		
		memset(dr, 0, 52 * sizeof(int));
		for(i = 0; c = s[i]; i++)
			(c >= 'a' && c <= 'z') ? ++dr[c - 'a'] : ++dr[c - 'A' + 26];

		for(i = 0, result = 1, terms = 0; i < 52; terms += dr[i++])
		{
			for(j = terms + 1, temp = 1; j <= terms + dr[i]; j++)
				temp *= j;
			result = (result % MOD) * (temp / factorial(dr[i]));
		}

		for(i = terms + 1; i <= nr; i++)
			result = (result % MOD) * i;

		printf("%d\n", (int) (result % MOD));
	}
	return 0;
}

