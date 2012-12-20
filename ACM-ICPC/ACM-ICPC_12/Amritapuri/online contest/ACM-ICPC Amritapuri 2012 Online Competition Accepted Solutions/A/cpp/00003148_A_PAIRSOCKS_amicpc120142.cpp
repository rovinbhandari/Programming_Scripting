#include <cstdio>
#include <string>
#include <cstring>

typedef unsigned int uint;

#define FOR(i, a, b) 		for(int i = a; i <= b; i++)
#define REP(i, n) 			for(uint i = 0; i < n; i++)
#define TEST_CASE(io, t) 	for(uint t = io.nextUInt(); t--;)
#define NEXT_LINE 			putchar_unlocked('\n');

using namespace std;

/*
 * Class in order to perform input/output faster than scanf/printf
 */
class FastIO
{
	public:
	uint nextUInt()
	{
		char ch = getchar_unlocked();
		register uint val = 0;

		while(ch < '0' || ch > '9')
			ch = getchar_unlocked();

		while(ch >= '0' && ch <= '9')
		{
			val = (val << 3) + (val << 1) + (ch - '0');
			ch = getchar_unlocked();
		}

		return val;
	}
	
	int nextInt()
	{
		char ch = getchar_unlocked();
		register int val = 0;
		int sign = 1;
		
		while(ch < '0' || ch > '9')
		{
			if(ch == '-')
				sign = -1;
				
			ch = getchar_unlocked();
		}
		
		while(ch >= '0' && ch <= '9')
		{
			val = (val << 3) + (val << 1) + (ch - '0');
			ch = getchar_unlocked();
		}
		
		return val * sign;
	}
	
	string next()
	{
		char ch;
		string res = "";
		
		while((ch = getchar_unlocked()) == '\n');
		
		while(ch != ' ' && ch != '\n')
		{
			res += ch;
			ch = getchar_unlocked();
		}
		
		res += '\0';
		
		return res;
	}
	
	string nextLine()
	{
		char ch;
		string res = "";
		
		while((ch = getchar_unlocked()) == '\n');
		
		while(ch != '\n')
		{
			res += ch;
			ch = getchar_unlocked();
		}
		
		res += '\0';
		
		return res;
	}
	
	void displayUInt(uint n)
	{
		register uint N = n , rev, count = 0;
		rev = N;

		if (!N)
		{
			putchar_unlocked('0');
			return;
		}

		while(!(rev % 10))
		{
			count++;
			rev /= 10;
		}
	
		rev = 0;
		while(N)
		{
			rev = (rev << 3) + (rev << 1) + N % 10;
			N /= 10;
		}

		while (rev)
		{
			putchar_unlocked(rev % 10 + '0');
			rev /= 10;
		}

		while(count--)
			putchar_unlocked('0');
	}
	
	void displayInt(int n)
	{
		if(n < 0)
		{
			putchar_unlocked('-');
			n = -n;
		}
		
		displayUInt(n);
	}
	
	void displayString(string str)
	{
		for(uint i = 0; str[i]; i++)
			putchar_unlocked(str[i]);
	}

};

int main()
{
	FastIO io;
	
	TEST_CASE(io, t)
	{
		bool freq[4] = { true, true, true, true };
		char ch;
		
		while((ch = getchar_unlocked()) != '\n' && ch != EOF)
		{
			switch(ch)
			{
				case 'R':
					freq[0] = !freq[0];
					break;
					
				case 'B':
					freq[1] = !freq[1];
					break;
					
				case 'G':
					freq[2] = !freq[2];
					break;
					
				case 'W':
					freq[3] = !freq[3];
			}
		}
		
		(freq[0] && freq[1] && freq[2] && freq[3])?	io.displayString("YES"): io.displayString("NO");
		NEXT_LINE;
		
	}
	
	return 0;
}
