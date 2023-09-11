#include <stack>
#include <cstdio>
#include <iostream>
using namespace std;

int main(void)
{
	int t, i, j;
	bool islastcolon, isbalanced;
	char c;
	stack<char> st;
	scanf("%d", &t);
	c = getchar();
	for(i = 0; i < t; i++)
	{
		while(!st.empty())
			st.pop();
		isbalanced = true;
		while((c = getchar()) != '\n' && c != EOF)
		{
			if(c == ':')
				islastcolon = true;
			else
			{
				if(islastcolon && (c == ')' || c == '('))
					c = 's';
				islastcolon = false;
				if(c == '(')
					st.push('(');
				else if(c == ')')
					if(st.empty())
						isbalanced = false;
					else
						st.pop();
			}
		}
		if(isbalanced && st.empty())
			printf("Case #%d: %s\n", i + 1, "YES");
		else
			printf("Case #%d: %s\n", i + 1, "NO");
	}
	return 0;
}

