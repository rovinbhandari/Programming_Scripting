#include <cstdio>
#include <string>
#include <iostream>

using std::string;

int main()
{
	int t;

	string input;
	scanf("%d", &t);

	while(t--)
	{
		std::cin>>input;

		int i = 1;

		for( ; i < input.size(); i+=2)
		{
			printf("%c", input[i]);
		}

		i = 0;

		for(; i < input.size(); i+=2)
		{
			printf("%c", input[i]);
		}
		printf("\n");
	}

	return 0;
}
