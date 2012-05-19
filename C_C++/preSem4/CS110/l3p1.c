#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main()
{
        int i, j, k, n, flag = 0;
        time_t t;
        srand((unsigned) time(&t));
	printf("\nEnter value of n (<100) : ");
	scanf("%d", &n);
        float a[n][2];
	printf("\n\nGenerated points are : \n");
        for(i = 0; i < n; i++)
        {      
		printf("(");
		 for(j = 0;j < 2; j++)
                {
                        a[i][j] = ((float) (rand() % 100)) / 10.0;
                	printf("%f", a[i][j]);
			if(j == 0)
			{
				printf(", ");
			}
		}
                printf(")\n");
        }
	for(i = 0; i < n; i++)
	{
		for(j = i + 1; j < n; j++)
		{
			for(k = j + 1; k < n; k++)
			{
				if(((a[i][0] - a[j][0]) / (a[i][1] - a[j][1])) == ((a[i][0] - a[k][0]) / (a[i][1] - a[k][1])))
             	   		{
					printf("\nThe points (%f,%f), (%f,%f), (%f,%f)  are collinear\n", a[i][0], a[i][1], a[j][0], a[j][1], a[k][0], a[k][1]);
       					flag = 1;
				}
                	}
		}
	}
	if(flag==0)
	{
		printf("\nThe points are not collinear\n");	
	}
}
