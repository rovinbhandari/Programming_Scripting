#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

#define DBGSTR "DBG:\t"
#define DBGINI stderr, DBGSTR

void fprintfarray(int* a, int l)
{
	int i = 0;
	while(i < l)
		fprintf(stderr, "%d ", a[i++]);
	fprintf(stderr, "\n");
}

int main(void)
{
	int n, k, in, i;
	scanf("%d", &n);
	fprintf(DBGINI "n = %d\n", n);
	scanf("%d", &k);
	fprintf(DBGINI "k = %d\n", k);
	int* kmaxheap = (int*) malloc(sizeof(int) * (k + 1));
	fprintf(DBGINI "malloc(): kmaxheap = ");
	fprintfarray(kmaxheap, k + 1);
	i = k;
	while(i--)
		scanf("%d", &kmaxheap[i]);
	fprintf(DBGINI "scanf()s: kmaxheap = ");
	fprintfarray(kmaxheap, k + 1);
	make_heap(&kmaxheap[0], &kmaxheap[k]);
	fprintf(DBGINI "make_heap(): kmaxheap = ");
	fprintfarray(kmaxheap, k + 1);
	i = n - k;
	while(i--)
	{
		scanf("%d", &in);
		fprintf(DBGINI "in = %d\n", in);
		if(in == -1)
			printf("%d\n", kmaxheap[0]);
		else if(in < kmaxheap[0])
		{
			pop_heap(&kmaxheap[0], &kmaxheap[k]);
			fprintf(DBGINI "pop_heap(): kmaxheap = ");
			fprintfarray(kmaxheap, k + 1);
			kmaxheap[k - 1] = in;
			fprintf(DBGINI "add element: kmaxheap = ");
			fprintfarray(kmaxheap, k + 1);
			push_heap(&kmaxheap[0], &kmaxheap[k]);
			fprintf(DBGINI "push_heap(): kmaxheap = ");
			fprintfarray(kmaxheap, k + 1);
		}			
	}
	return 0;
}

