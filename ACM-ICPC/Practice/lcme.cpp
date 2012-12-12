#include <iostream>
using namespace std;

typedef unsigned long long int ulli;

ulli lcm(int x, int y)
{
	int a = x;
	int b = y;
	while(a != b)
		if(a < b)
			a += x;
		else
			b += y;
	return a;
}

ulli allpairlcm(int n)
{
	ulli sum, tsum, l;
	sum = 0;
	for(int i = 1; i <= n; i++)
	{
		tsum = 0;
		for(int j = i + 1; j <= n; j++)
		{
			l = lcm(i, j);
			cout << i
				 << ", "
				 << j
				 << " :\t\t"
				 << l
				 << endl;
			tsum += l;
		}
		if(i != n)
			cout << "=== "
				 << tsum
				 << " ==="
				 << endl;
		sum += tsum;
	}
	return sum;
}

int main(void)
{
	int t, n;
	cin >> t;
	while(t--)
	{
		cin >> n;
		cout << endl
			 << "### "
			 << allpairlcm(n)
			 << " ###"
			 << endl
			 << "##############"
			 << endl
			 << endl;
	}
	return 0;
}
