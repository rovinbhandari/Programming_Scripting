#include <stdio.h>

int main()
{
	int red, green, black, white, i, j, k;
	char x;

	scanf("%d",&i);
	scanf("%c",&x);

	while(i--)
	{
		red = green = black = white = 0; 

		scanf("%c",&x);
		while(x!='\n')
		{
			switch(x)
			{
				case 'R': red = (red+1)%2; break;
				case 'G': green = (green+1)%2; break;
				case 'W': white = (white+1)%2; break;
				case 'B': black = (black+1)%2;
			}
			scanf("%c",&x);
		}
			

		if(red == 0 && green == 0 && white == 0 && black == 0)
			printf("YES\n");
		else
			printf("NO\n");
	}

	return 0;
}
