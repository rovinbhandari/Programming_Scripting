#include<stdio.h>

int checkValid(char str[]);

int main(void)
{
	int t, i;
	char str[1000][51];
	scanf("%d", &t);
	for(i = 0;i < t; i++)
		scanf("%s", str[i]);
	for(i = 0; i<t; i++)
	{
		if(checkValid(str[i]))
			printf("YES\n");
		else
			printf("NO\n");
	}
	return 0;
}

int checkValid(char str[])
{
	int i, valid;
	int r, g, b, w;
	r = g = b = w = 0;
	for(i = 0; str[i] != '\0'; i++)
	{
		if(str[i] == 'R')	r++;
		else if(str[i] == 'G')	g++;
		else if(str[i] == 'B')	b++;
		else if(str[i] == 'W')	w++;
		
	}
	return r%2==0 && g%2==0 && b%2==0 && w%2==0;
}
