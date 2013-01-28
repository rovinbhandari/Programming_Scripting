#include <algorithm>
#include <cstdio>
#include <cstring>
using namespace std;

int main(void)
{
	int m, a[26], i, j, sum;
	char c;
	scanf("%d", &m);
	c = getchar();
	for(i = 0; i < m; i++)
	{
		memset(a, 0, 26 * sizeof(int));
		while((c = getchar()) != '\n' && c != EOF)
		{
			if(c >= 'a' && c <= 'z')
				a[c - 'a']++;
			else if(c >= 'A' && c <= 'Z')
				a[c - 'A']++;
		}
		sort(a, a + 26);
		sum = 0;
		for(j = 25; j >= 0; j--)
			sum += (j + 1) * a[j];
		printf("Case #%d: %d\n", i + 1, sum);
	}
	return 0;
}
