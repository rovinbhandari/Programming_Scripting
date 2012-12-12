#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int main()
{
	int T;
	scanf ("%d",&T);
	while (T--)
	{
		int count[26] = {0};
		string s;
		cin >> s;
		int t1,t2,t3,t4;
		//int count = 0;
		t1 = 'R' - 'A';
		t2 = 'G' - 'A';
		t3 = 'B' - 'A';
		t4 = 'W' - 'A';
		for (int i = 0; i < s.length(); i++)
		{
			count[s[i] - 'A']+= 1;
			
		}
		if (count[t1]%2 == 0 and count[t2]%2 == 0 and count[t3]%2 == 0 and count[t4]%2 == 0)
		{
			printf ("YES\n");
		}
		else
			printf ("NO\n");
	}
}
