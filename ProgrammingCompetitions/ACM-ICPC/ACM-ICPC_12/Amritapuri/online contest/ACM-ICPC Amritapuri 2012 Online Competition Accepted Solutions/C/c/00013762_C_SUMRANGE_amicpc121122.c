#define MAX_LEN 1000000
#include <stdio.h>

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
    int T,i,j,k,t,n,p,q,r,N;
    long int L,H,a[MAX_LEN];
    long int result[100]={0},rl;
    
    scanf("%d",&T);
//    result = (long int *)calloc(T,sizeof(long int));    
    for(t=0;t<T;t++)    
    {
  
       scanf("%d %ld %ld",&N,&L,&H);
       
       //a = (long int *)malloc(sizeof(long int)*N);

       for(p=0;p<N;p++)
       {  
           scanf("%ld",&a[p]);
       }

       mergesort(a, 0, N-1);
       for(i=0;i<N;i++)
       {

        if(a[i]>H) 
               break;                   
        for(j=i+1;j<N;j++)
        {
            if(a[i]+a[j]>H) 
                break;
            for(k=j+1;k<N;k++)
            {
                   long int sum = a[i]+a[j]+a[k]; 
		   if(sum>H)
			break;
                   if(L<=sum && sum<=H)
                   {
                        result[t]++;                  
                   }
            }            
        }
       }
       
     //  free(a);       
    }
    
    ////////////print result
    for(i=0;i<T;i++)   
    {
        printf("%ld\n",result[i]);
    }
    return 0;
}
