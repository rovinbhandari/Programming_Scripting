#include <cstdio>
#include <algorithm>
using namespace std;

//#define DBG true
#define DBG false

#define MAXSIZEa (1000 + 1)
int a[MAXSIZEa];

int n, l, h;

int nooftuples();
int nooftuples2();

int main (void)
{
  int i, t;

  scanf ("%d", &t);

  while (t--)
  {
    scanf("%d", &n);
    scanf("%d", &l);
    scanf("%d", &h);

	for(i = 1; i <= n; i++)
		scanf("%d", &a[i]);
	
	sort(a, a + n + 1);
	if(DBG)
	{
		fprintf(stderr, "\tl = %d, h = %d\n\t", l, h);
		for(i = 1; i <= n; i++)
			fprintf(stderr, "%d ", a[i]);
		fprintf(stderr, "\n");
	}

    if(DBG) fprintf(stderr, "%d\n", nooftuples());
    printf("%d\n", nooftuples2());

  }
  return 0;
}

int nooftuples2()
{
	int x = 0, i, j, j2, k, t;
	for(i = 1; i <= n - 2; i++)
	{
		j = i + 1;
		k = n;
		while(k > j)
		{
			if((t = a[i] + a[j] + a[k]) <= h && t >= l)
			{
				x++;
				if(DBG) fprintf(stderr, "\t(%d, %d, %d) : (%d, %d, %d)\n", i, j, k, a[i], a[j], a[k]);
				if(k - 1 != j)
				{
					j2 = k - 1;
					while(a[i] + a[j2] + a[k] > h)
						j2--;
					x += j2 - j;
					if(DBG)
					{
						for(int p = j2; p > j; p--)
							fprintf(stderr, "\t(%d, %d, %d) : (%d, %d, %d)\n", i, p, k, a[i], a[p], a[k]);
					}
				}
				k--;
			}
			else if(t > h)
				k--;
			else if(t < l)
				j++;
		}
	}
	return x;
}

int nooftuples()
{
	int x = 0, t;
	iloop:
	for(int i = 1; i <= n  - 2; i++)
	{
		if(a[i] > h)
			break;
		jloop:
		for(int j = i + 1; j <= n - 1; j++)
		{
			if((t = a[i] + a[j]) > h)
				goto jloopend;
			kloop:
			for(int k = j + 1; k <= n; k++)
				if(t + a[k] >= l && t + a[k] <= h)
				{
					if(DBG) fprintf(stderr, "\t(%d, %d, %d) : (%d, %d, %d)\n", i, j, k, a[i], a[j], a[k]);
					x++;
				}
		}
		jloopend:
		continue;
	}
	return x;
}


