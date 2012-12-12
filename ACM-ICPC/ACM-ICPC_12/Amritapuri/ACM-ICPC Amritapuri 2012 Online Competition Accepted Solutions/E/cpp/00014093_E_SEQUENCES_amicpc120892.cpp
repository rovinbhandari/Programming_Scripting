#include <stdio.h>

int max(int a, int b)
{
	if(a>b)
		return a;
	return b;
}

using namespace std;

#define MAXN 100007

char str[MAXN];
int zeros[MAXN], ones[MAXN], input[MAXN];

struct data
{
	int Max;
};
typedef struct data Tree;
Tree t[4*MAXN];

void combine(Tree& dest, Tree& src1, Tree& src2)
{
	dest.Max = max(src1.Max, src2.Max);
}

void init_data(int v, int index)
{
	t[v].Max = input[index];
}

void build(int v, int l, int r)
{
	if (l == r)
		init_data(v, l);
	else
	{
		int mid = (l + r)/2;
		build(2*v, l, mid);
		build(2*v+1, mid+1, r);
		combine(t[v], t[2*v], t[2*v+1]);
	}
}

Tree query(int v, int l, int r, int a, int b)
{
	if (r<a or b<l)
		return (Tree){0};

	if (a<=l and r<=b)
		return t[v];
	int mid = (l + r)/2;
	if (b <= mid)
		return query(2*v, l, mid, a, b);
	else if (a > mid)
		return query(2*v+1, mid+1, r, a, b);
	else
	{
		Tree t1, t2, t3;
		t1 = query(2*v, l, mid, a, b);
		t2 = query(2*v+1, mid+1, r, a, b);
		combine(t3, t1, t2);
		return t3;
	}
}

int main()
{
	int T, N, Q, a, b;
	int i;
	
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d", &N);
		scanf("%s", str+1);
		zeros[0] = ones[0] = 0;
		for (i=1; i<=N; i++)
		{
			zeros[i] = zeros[i-1];
			ones[i] = ones[i-1];
			if (str[i] == '0')
				zeros[i]++;
			else
				ones[i]++;
		}
		zeros[N+1] = zeros[N];
		ones[N+1] = ones[N];
		for (i=1; i<=N; i++)
		{
			input[i] = zeros[i] - ones[i];
			if(str[i]=='1')
				input[i]++;
			//printf("%d\n", input[i]);
		}
		
		build(1, 1, N);
			
		scanf("%d", &Q);
		for (i=0; i<Q; i++)
		{
			scanf("%d %d", &a, &b);
			if(a==0 and b==0)
				;
			if(a==0 and b!=0)
				;
			if (a == b)
				printf("1\n");
			else
				printf("%d\n", query(1, 1, N, a, b).Max - zeros[a-1] + ones[b]);
		}
	}
	
	return 0;
}
