#include<stdio.h>
int search(int a[], int l, int u, int num)
{
	int mid = (l + u) / 2;
	static int d = -1;
	if(l < u)
	{
		if(a[mid] == num)
		{
			d = mid;
		}
		else if(a[l] == num)
                {
                        d = l;
                }
		else if(a[u] == num)
                {
                        d = u;
                }
		else if(a[mid] < num)
		{
			l = mid + 1;
			search(a, l, u, num);
		}
		else if(a[mid] > num)
		{
			u = mid - 1;
			search(a, l, u, num);
		}
	}
	return d;
}
int main()
{
	int a[100], l, u, num, n, x = -1, i, j, temp;
	printf("\nEnter size of array\n");
	scanf("%d", &n);
	printf("\nEnter the data\n");
	for(i=0; i < n; i++)
	{
		scanf("%d", &a[i]);
	}
	for(i = 0; i < n; i++)
	{
		for(j = i; j < n; j++)
		{
			if(a[i] > a[j])
			{
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	printf("\nAfter sorting, array is :\n");
	for(i = 0; i < n; i++)
	{
		printf("%d ", a[i]);
	}
	l = a[0];
	u = a[n-1];
	printf("\nEnter the element to search\n");
	scanf("%d", &num);
	x = search(a, l, u, num);
	if(x == -1)
	{
		printf("\nElement not found\n");
	}
	else
	{
		printf("\nElement #%d# found at position : %d\n", num, x+1);
	}
	return(0);
}
