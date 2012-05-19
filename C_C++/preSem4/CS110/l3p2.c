#include<stdio.h>
#include<math.h>
int main()
{
	int i, j, temp, min, n;
	float am = 0, gm = 1, hm = 0, sd = 0, md = 0, med;
	printf("\n\n\tEnter the number of data items(n): ");
	scanf("%d",&n);
	float arr[n], sortarr[n];
	printf("\n\tEnter data :\n");
	int x = n;
	for(i = 0; i < x; i++)
	{
		printf("\t");
		scanf("%f",&arr[i]);
		am += arr[i];
		gm *= arr[i];
		hm += 1/arr[i];
	}
	am /= n;
	gm = pow(gm, (1 / (float) n));
	hm = n / hm;
	printf("\n\tArithmetic mean = %f\n", am);
	printf("\n\tGeometric mean = %f\n", gm);
	printf("\n\tHarmonic mean = %f\n", hm);
	for(i = 0; i < x; i++)
	{
		sd += pow((arr[i] - am), 2);
		md += (fabs(arr[i] - am));
	}
	sd = pow((sd / n), 0.5);
	md /= n;
	printf("\n\tStandard deviation = %f\n", sd);
	printf("\n\tMean deviation about mean= %f\n", md);
	for(i = 0; i < x - 1; i++)
	{
		min = i;
		for(j = i + 1; j < x; j++)
		{
			if(arr[j] < arr[min])
			{	
				min = j;	
			}
			temp = arr[i];
			arr[i] = arr[min];
			arr[min] = temp;
		}	
	}
	med = (n % 2 == 0) ? ((arr[n / 2 - 1] + arr[n / 2]) / 2) : (arr[n / 2]);
        for(i = 0; i < n; i++)
	{
		md += (fabs(arr[i] - med));
	}
	md /= n;
	printf("\n\tMean Deviation about median = %f\n\n\n", md);
}
