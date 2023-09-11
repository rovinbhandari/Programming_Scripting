#include <iostream>
using namespace std;

int nothing(int x)
{
	return x;
}

int main()
{
	int t, n;
	cin>>t;
	while(t--)
	{
		cin>>n;
		cout<<nothing(n)<<"\n";
	}
	return 0;
}

