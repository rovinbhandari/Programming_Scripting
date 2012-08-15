#include <cstdio>
#include <cstdlib>
#include <algorithm>
using namespace std;

int main(void)
{
	int n, k, in, i;
	scanf("%d", &n);
	scanf("%d", &k);
	int* kmaxheap = (int*) malloc(sizeof(int) * (k + 1));
	i = k;
	while(i--)
		scanf("%d", &kmaxheap[i]);
	make_heap(&kmaxheap[0], &kmaxheap[k]);
	i = n - k;
	while(i--)
	{
		scanf("%d", &in);
		if(in == -1)
			printf("%d\n", kmaxheap[0]);
		else if(in < kmaxheap[0])
		{
			pop_heap(&kmaxheap[0], &kmaxheap[k]);
			kmaxheap[k - 1] = in;
			push_heap(&kmaxheap[0], &kmaxheap[k]);
		}			
	}
	return 0;
}
