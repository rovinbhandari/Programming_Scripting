// Recursive function which returns the same array if size is 1
// Otherwise calls the same on first half and second half
// Later merges them
#include <stdio.h>
void mergesort( int n, int *a )
{
	if( n == 1 ) ;
	else
	{
		int temp[n], val1, val2, val3;
		mergesort( n/2, a );
		mergesort( n-n/2, (a+n/2) );

		val1 = val2 = val3 = 0;

		for( ; val1 < n/2 && val2 < n-n/2; val3++ )
		{
			if( *(a+val1) < *(a+n/2+val2) ) 
			{
				temp[val3] = *(a+val1);
				val1++;
			}
			else
			{
				temp[val3] = *(a+n/2+val2);
				val2++;
			}
		}

		if( val1 < n/2 )
			while( val1 < n/2 )
				temp[val3++] = *(a+val1++);
		else if( val2 < n-n/2 )
			while( val2 < n-n/2 )
				temp[val3++] = *(a+n/2+val2++);

		for( val1=0; val1<n; val1++ ) *(a+val1) = temp[val1];
	}

}

int binarysearch(int* arr, int start, int end, int lesser, int higher)
{
	int middle;
	int end_start=end, start_start=start;

	while(start<end)
	{
		middle = (start+end)/2;
		if(arr[middle] == lesser)
			break;
		else if(lesser > arr[middle])
			start = middle+1;
		else
			end = middle-1;
	}

	if(start==end)
		middle = start;

	while(arr[middle]<lesser)
		middle++;
	
	int count=0;
	for(; middle<=end_start && arr[middle] <= higher; middle++)
	{
		count++;
	}
	
	return count;
}

int main()
{
	int arr[1001], i, j, l;
	int size, lesser, higher;

	for(i=0; i<10; i++)
		arr[i] = i;

	int tests;

	scanf("%d",&tests);

	while(tests--)
	{
		scanf("%d %d %d",&size,&lesser,&higher);

		for(i=0; i<size; i++)
			scanf("%d",&arr[i]);
		mergesort(size,arr);
		int count=0;

		for(i=0; i<size; i++)
			for(j=i+1; j<size; j++)
			{
				count += binarysearch(arr,j+1,size-1,lesser-arr[i]-arr[j],higher-arr[i]-arr[j]);
			}

		printf("%d\n",count);
	}

	return 0;
}
