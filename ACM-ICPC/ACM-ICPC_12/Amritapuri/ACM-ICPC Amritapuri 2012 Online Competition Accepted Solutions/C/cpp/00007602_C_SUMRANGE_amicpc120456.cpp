#include<stdio.h>


void swap(int& a, int& b)
{
    int temp = a;
    a = b;
    b = temp;
}

int partition(int arr[], int low, int high)
{
    int pivot = low;

    int i = low;
    int j = high+1;

    while(1)
    {
        while(arr[++i]<arr[pivot])
            if(i == high) break;

        while(arr[pivot]<arr[--j])
            if(j == low) break;

        if(i >= j)
            break;

        swap(arr[i], arr[j]);
    }

    swap(arr[pivot], arr[j]);

    return j;
}

void quicksort(int arr[], int low, int high)
{
    if (high <= low) return;

    int pivot = partition(arr, low, high);
    quicksort(arr, low, pivot-1);
    quicksort(arr, pivot+1, high);
}


int main()
{
    int count_testcases;
    scanf("%d\n", &count_testcases);

    int N,L,H;
    int temp;
    int arr[1000];
    int i,j,k;
    int count;
    while(count_testcases--)
    {
        scanf("%d %d %d \n", &N, &L, &H);

        for(temp=0;temp<N;temp++)
            scanf("%d", &arr[temp]);

        quicksort(arr, 0, N-1);

        count = 0;

        for(i = 0; i< N-2; i++)
        for(j = i+1; j< N-1; j++)
        for(k = j+1; k< N; k++)
        {
            if((arr[i]+arr[j]+arr[k] >= L)&&(arr[i]+arr[j]+arr[k] <= H))
            {
                count++;
                //printf("i:%d j:%d k:%d \n", arr[i], arr[j], arr[k]);
            }
            else if(arr[i]+arr[j]+arr[k] > H)
                break;
        }

        printf("%d\n", count);
    }
    return 0;
}
