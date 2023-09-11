#include <stack>
#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string s;

bool isBalanced(int b, int e)
{
	if(b == e)
	{
		if(s.at(b) == '(' || s.at(b) == ')')
			return false;
		else
			return true;
	}
	else if(b > e)
		return false;
	return false;
}

int main(void)
{
	int t, i;
	scanf("%d", &t);
	for(i = 0; i < t; i++)
	{
		cin >> s;
		if(isBalanced(0, s.length() - 1))
			printf("Case #%d: %s\n", i + 1, "YES");
		else
			printf("Case #%d: %s\n", i + 1, "NO");
	}
	return 0;
}

