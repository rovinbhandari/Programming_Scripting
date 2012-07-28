#include <math.h>
#include <stdio.h>
#include <string.h>

#define DBG 1
#define DBGOUT(m, x)	do	\
						{	\
							if(DBG)	\
								printf("" #m "" #x);	\
						}	\
						while(0);

#define MOD	1000000007

typedef unsigned int ui;
typedef unsigned short int usi;
typedef unsigned long long int ulli;

const usi primes1_500[] =		{2, 3, 5, 7,
								11, 13, 17, 19,
								23, 29,
								31, 37,
								41, 43, 47,
								53, 59,
								61, 67,
								71, 73, 79,
								83, 89, 97,
								101, 103, 107, 109,
								113,
								127,
								131, 137, 139,
								149,
								151, 157,
								163, 167,
								173, 179,
								181,
								191, 193, 197, 199,
								211, 223, 227, 229,
								233, 239,
								241, 251, 257,
								263, 269, 271, 277,
								281, 283, 293,
								307, 311, 313, 317,
								331, 337, 347, 349,
								353, 359, 367,
								373, 379, 383, 389,
								397,
								401, 409, 419, 421,
								431, 433, 439,
								443, 449, 457,
								461, 463, 467,
								479, 487, 491, 499};

const usi primefactors2_10[][4] = {
									{1, 0, 0, 0},
									{1, 1, 0, 0},
									{3, 1, 0, 0},
									{3, 1, 1, 0},
									{4, 2, 1, 0},
									{4, 2, 1, 1},
									{7, 2, 1, 1},
									{7, 4, 1, 1},
									{8, 4, 2, 1}
								 };
enum singledigitprimes {
							TWO,
							THREE,
							FIVE,
							SEVEN
					   };
#define PRIMEFACTORS2_10(n, p) primefactors2_10[n - 2][p]

usi dr[11];
usi chars[52];

void setdr(char* s)
{
	memset(chars, 0, 52);
	do
		chars[*s - ((*s <= 'Z') ? 'A' : 'a')]++;
	while(*++s);
	memset(dr, 0, 11);
	usi i = 0;
	while(i < 52)
		dr[chars[i++]]++;
}

inline usi primepowerfactorial(usi x, usi p)
{
	usi power = 0;
	while(x /= p)
		power += x;
	return power;
}

inline ulli powermod(usi a, usi b)
{
	ulli pro = 1;
	while(b-- >= 1)
		pro = (pro * a) % MOD;
	return pro;
}

ui compute(usi nr)
{
	ulli result = 1;
	return (ui) result;
}

char input[501];

int main(void)
{
	int t;
	scanf("%d", &t);
	while(t--)
	{
		fgets(input, 501, stdin);
		if(strlen(input) == 1)
			printf("1\n");
		else
		{
			setdr(input);
			printf("%u\n", compute(strlen(input)));
		}
	}
	return 0;
}

