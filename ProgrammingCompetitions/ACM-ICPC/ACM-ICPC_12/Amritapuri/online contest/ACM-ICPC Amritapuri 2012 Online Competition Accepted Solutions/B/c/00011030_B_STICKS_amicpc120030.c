#include <stdio.h>
//#include <stdlib.h>
//#include <math.h>
#define LL long long int

LL l[50010];
int l_len;
/*
int cmp (const void* a, const void* b)
{
	return *((float*) a) > *((float*) b);
}
*/

int main()
{
	int t;
	int m, n;
	LL m_size;
	LL a, b, c, d;
	int ans, x;
	scanf ("%d", &t);
	while (t--)
	{
		scanf ("%d %d", &m, &n);
		l_len = m;
		m_size = 0;
		ans = 0;
		while (m--)
		{
			scanf("%lld", &l[m]);
			l[m] *= l[m];
		}
//		qsort (l, l_len, sizeof (float), cmp);
		while (n--)
		{
			scanf("%lld %lld %lld", &a, &b, &c);
			d = a*a + b*b + c*c;
			if (d > m_size)
				m_size = d;
		}
/*
		for (ans = l_len - 1; ans >=0; ans--)
			if (l[ans] <= m_size)
				break;
*/
		for (x = 0; x < l_len; x++)
		{
			if (l[x] <= m_size)
				ans++;
		}
		printf ("%d\n", ans);
	}
	return 0;
}
