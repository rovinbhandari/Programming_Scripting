#include <stdio.h>
int main()
{
	int amt, n, i = 0, a[] = {100,50,25,20,10,5,1}, b[7];
	printf("\nEnter the amount of currency\n");
	scanf("%d", &amt);
	n = amt;
	while(n != 0)
	{
		if(i == 2)
		{
			i++;
		}
		b[i] = n / a[i];
		n = n % a[i];
		i++;
	}
	while(((b[3] > b[5]) ? b[5] : b[3]) != 0)
	{
		b[2]++;
		b[3]--;
		b[5]--;
	}
	printf("\nThe number of different notes to be given for an amount of %d are : \n", amt);
	for(i = 0; i < 7; i++)
	{
		printf("%d\tX\t%d\n", a[i], b[i]);
	}
	return(0);
}
