#include<stdio.h>
void merge(long int arr[], long int low, long int mid, long int high)
{
    long int size_array1 = mid - low + 1;
    long int size_array2 = high - mid;
    long int array1[size_array1], array2[size_array2];
    long int i = 0, j=0, k=0;

    for (i = 0; i < size_array1; i++)
		array1[i] = arr[low + i];
    for (j = 0; j < size_array2; j++)
		array2[j] = arr[mid + j + 1];

    i = 0;
    j = 0;
    for (k = low; k <= high; k ++)
    {
	    if ( j == size_array2 )
	    {
		arr[k] = array1[i];
		i++;
	    }
	    else if ( i == size_array1 )
	    {
		arr[k] = array2[j];
		j++;
	    }
	    else if (array1[i] <= array2[j])
	    {
		arr[k] = array1[i];
		i++;
	    }
	    else
	    {
		arr[k] = array2[j];
		j++;
	    }
    }
}

void mergesort(long int arr[], long int low, long int high)
{
    long int mid;

    if (low < high)
    {
	mid = (low + high) / 2;
	mergesort(arr, low, mid);
	mergesort(arr, mid + 1, high);
	merge(arr, low, mid, high);
    }
}

int main()
{
    int T;
    long int N,M,L[50000],A[50000],B[50000],C[50000],i,j,k;
    long int result[50000];	
    scanf("%d",&T);
    
    for(i=0;i<T;i++)
    {
    	scanf("%ld%ld",&N,&M);
    	long int max=0;
    	for(j=0;j<N;j++)
    	{	
    		scanf("%ld",&L[j]);
    	}
 	mergesort(L, 0, N-1);   	
	long int maxdiagonal = 0;
    	for(j=0;j<M;j++)
    	{	
    		scanf("%ld%ld%ld",&A[j],&B[j],&C[j]);
   		long int  diagonal = (A[j]*A[j]+B[j]*B[j]+C[j]*C[j]);

		if(maxdiagonal<diagonal)
			maxdiagonal = diagonal;
	}
   		long int count = 0;
	    	for(k=0;k<N;k++)
	    	{

	 		if((L[k]*L[k]) <= maxdiagonal)
	 			count++;	 		  		
			else
				break;
	    	} 
	    	if(max<count)
	    		max= count;
    	result[i]=max;
    }
      ////////////print result
    
    for(i=0;i<T;i++)   
    {
        printf("%ld\n",result[i]);
    }
    return 0;
}
