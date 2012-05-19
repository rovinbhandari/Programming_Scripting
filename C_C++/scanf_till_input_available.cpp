#include <cstdio>
using namespace std;

int main()
{
	int temp, n;
	while(1)
	{
		temp = scanf("%d", &n);
		printf("%d\n", temp);
		if(temp <= 0)
			break;
	}
	return 0;
}

/*
	Since scanf returns 1 on reading an integer and -1 on reading a blank new line or an EOF, the code for reading integers can be written as:
int main()
{
	int n;
	while(scanf("%d", &n) > 0)
		printf("%d\n", function(n);
	return 0;
}
*/		
