#include <algorithm>
#include <cstdio>
#include <cstring>
#include <climits>
#include <vector>
using namespace std;

int lightson[52];

int main(void)
{
	int t, n, m, k;
	char c;
	scanf("%d", &t);
	while(t--)
	{
		scanf("%d %d %d", &n, &m, &k);
		c = getchar();
		memset(lightson, 0, sizeof(int) * 52);
		int i = 0;
		do
			while((c = getchar()) != '\n')
				if(c == '*')
					lightson[i]++;
		while(++i < n);
		sort(&lightson[0], &lightson[n]);
		#ifdef DBG
		for(i = 0; i < n; i++)
			printf("%d ", lightson[i]);
		printf("\n");
		#endif
		int* pindex = lower_bound(&lightson[0], &lightson[n], m / 2 + 1);
		int index = (pindex - lightson) - 1;
		#ifdef DBG
		printf("index = %d\n", index);
		#endif

		for(i = 0; i <= index; i++, k--)
			lightson[i] = m - lightson[i];

		if(k % 2)
		{
			if(index == -1)
				lightson[0] = m - lightson[0];
			else if(index == n - 1)
				lightson[index] = m - lightson[index];
			else if(lightson[index] < lightson[index + 1])
				lightson[index] = m - lightson[index];
			else
				lightson[index + 1] = m - lightson[index + 1];
		}

		int sum = 0;
		for(i = 0; i < n; i++)
			sum += lightson[i];

		printf("%d\n", sum);
	}
	return 0;
}
