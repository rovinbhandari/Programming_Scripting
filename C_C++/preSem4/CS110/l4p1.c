#include<stdio.h>
#include<math.h>
void BtoD(char a[])
{
	int j, n, x=0, k;
	printf("\n\tCOVERSION FROM BINARY TO DECIMAL\n");
	for(n = 0; a[n] != '\0'; n++);
	n--;
	for(j = 0; a[j] != '\0'; j++)
	{	
		if(a[j] == 48)
		{
			k=0;
		}
		else if(a[j] == 49)
		{
			k=1;	
		}
		x += k * pow(2, n);
		n--;
	}
	printf("\n\tThe Number in Decimal is : %d\n\n", x);
}
void DtoB(int b)
{
	int x[50], i = 0;
	printf("\n\tCOVERSION FROM DECIMAL TO BINARY\n");
	while(b != 0)
	{
		x[i] = b % 2;
		b /= 2;
		i++;
	}
	printf("\n\tThe number in Binary is : \n\n\t");
	for(--i; i >= 0; i--)
	{
		printf("%d", x[i]);
	}
	printf("\n\n");
}
void HtoD(char a[])
{
	int j, n, x = 0, b;
	 printf("\nCOVERSION FROM HEX TO DECIMAL\n");
	for(n = 0; a[n] != '\0'; n++);
	n--;
	for(j = 0; a[j] != '\0'; j++)
	{	
		if(a[j] < 58)
		{	
			b = a[j] - 48;
		}
		else if((a[j] > 58) && (a[j] < 72))
		{
			b = a[j] - 55;
		}
		else
		{
			b = a[j] - 87;
		}
		x += b * pow(16, n);
		n--;
	}
	printf("\n\tThe number in Hexadecimal is  : %d\n\n", x);	
}
void DtoH(int b)
{
	printf("\n\tCOVERSION FROM DECIMAL TO HEX\n");
	int i = 0, k;
	char x[50];
        while(b != 0)
        {       k = b % 16;
		if(k >= 10)
		{
			x[i] = k + 55;
		}
		else
		{
			x[i] = k + 48;
		}
                b=b/16;
        	i++;
	}
        printf("\n\tThe number in Hexadecimal is : \n\n\t");
	for(--i; i >= 0; i--)
	{
		printf("%c", x[i]);
	}
	printf("\n\n");	
}
int main()
{
	int ch, i, b;
	char a[50];
	printf("\n\nEnter your choice :\n#1# Binary to decimal\n#2# Decimal to binary\n#3# Decimal to HEX\n#4# HEX to decimal\n");
	scanf("%d", &ch);
	printf("\n\nEnter the Number\n");
	if((ch == 1) || (ch == 4))
	{
		scanf("%s", a);
		for(i = 0; a[i] != '\0'; i++)
		{
                	if(!((a[i]>47 && a[i]<58) || (a[i]>64 && a[i]<71) || (a[i]>96 && a[i]<103)))
                        {
				printf("/n/n/tWRONG INPUT/n/n");
				return(0);
        		}
		}
	}
	else
	{
		scanf("%d", &b);
	}
	switch(ch)
	{
		case 1:	BtoD(a);
			break;
		case 2:	DtoB(b);
			break;
		case 3: DtoH(b);
			break;
		case 4: HtoD(a);
			break;
		default:
			return(0);
	}	
}
