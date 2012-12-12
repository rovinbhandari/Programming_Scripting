#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
	int t;
	int nums[1000];
	scanf("%d", &t);
	for(int i = 0; i < t; ++i)
	{
		int n, L, H, ct = 0;
		scanf("%d %d %d", &n, &L, &H);
		
		for(int j = 0; j < n; ++j)
			scanf("%d", &nums[j]);
		sort(nums, nums + n);
		for(int j = 0; j < n - 2; ++j)
		{
			int k = j + 1, l = n - 1;
			while(k < l)
			{
				int sum = nums[j] + nums[k] + nums[l];
				if(sum > H)
					--l;
				else if(sum < L)
					++k;
				else
				{
					++ct;
					sum -= nums[l];
					for(int m = l - 1; m >= 0 && sum + nums[m] >= L && k < m; --m)
						++ct;
					++k;
				}
			}
		}
		printf("%d\n", ct);
	}
}
