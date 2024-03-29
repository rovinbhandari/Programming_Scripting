/*	Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

	21 22 23 24 25
	20  7  8  9 10
	19  6  1  2 11
	18  5  4  3 12
	17 16 15 14 13

	It can be verified that the sum of the numbers on the diagonals is 101.

	What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?*/
#include <stdio.h>
void main()
{
	long side, inc, sum, num, i;
	side = 3;
	inc = 2;
	sum = num = 1;
	i = 0;
	while(side != (1001 + 2))
	{
		i++;
		num += inc;
		sum += num;
		if(i == 4)
		{
			i = 0;
			inc += 2;
			side += 2;
		}
	}
	printf("\n\tSum of diagonal numbers on a spiral of side %ld is %ld\n\n", (side - 2), sum);
}
