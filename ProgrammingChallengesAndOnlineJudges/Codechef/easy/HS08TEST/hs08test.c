#include <stdio.h>

int main(void)
{
	int w;
	float b, b2;
	scanf("%d %f", &w, &b);
	
	if(w % 5 == 0)
	{
		if((b2 = b - w - 0.5f) >= 0.0f)
			printf("%.2f\n", b2);
		else
			printf("%.2f\n", b);
	}
	else
		printf("%.2f\n", b);
	
	return 0;
}

