#include <stack>
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;

// by encoding the input string and stack into numbers, \
   try memoizing the values in a map for better performance.

bool isMatching(char a, char b)
{
	return a == '(' && b == ')';
}

bool isBalanced(string in, string st)
{
	if(in.empty())
		return st.empty();
	else if(in[0] == '(')
		return isBalanced(in.substr(1), in[0] + st);
	else if(in[0] == ')')
		return !st.empty() && isMatching(st[0], in[0])
						   && isBalanced(in.substr(1), st.substr(1));
	else if(in[0] == 'o')
		return isBalanced('(' + in.substr(1), '(' + st)
			   || isBalanced(in.substr(1), st);
	else if(in[0] == 'c')
		return (!st.empty() && isMatching(st[0], ')')
						   && isBalanced(in.substr(1), st.substr(1)))
			   || isBalanced(in.substr(1), st);
	else
		cerr << "GG" << endl;
}

int main(void)
{
	int t, i, j;
	bool islastcolon;
	char c;
	string pars;
	scanf("%d", &t);
	c = getchar();
	for(i = 0; i < t; i++)
	{
		pars.clear();
		islastcolon = false;
		while((c = getchar()) != '\n' && c != EOF)
		{
			if(c == ':')
				islastcolon = true;
			else
			{
				if(islastcolon)
				{
					if(c == ')')
						c = 'c';
					else if(c == '(')
						c = 'o';
					islastcolon = false;
				}
				if(c == 'c' || c == 'o' || c == '(' || c == ')')
					pars.push_back(c);
			}
		}
		if(isBalanced(pars, ""))
			printf("Case #%d: %s\n", i + 1, "YES");
		else
			printf("Case #%d: %s\n", i + 1, "NO");
	}
	return 0;
}

