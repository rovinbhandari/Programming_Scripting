#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

int main()
{
	int testCases;
	scanf("%d", &testCases);
	while( testCases-- )
	{
		string input;
		cin >> input;
		int a[4];
		a[0] = a[1] = a[2] = a[3] = 0;
		int len = input.length();
		for( int i =0; i < len; i++ )
		{
			if( input[i] =='R' )
				a[0]++;
			else if( input[i] == 'G' )
				a[1]++;
			else if( input[i] == 'B' )
				a[2]++;
			else if( input[i] == 'W' )
				a[3]++;
		}

		int flag =0;
		for( int i = 0; i < 4; i++ )
		{
			if( a[i]%2 != 0 )
			{
				flag = 1;
				break;
			}
		}
		if( flag == 0 )
			cout << "YES" << endl;
		else
			cout << "NO" << endl;

	}

	return 0;
}
