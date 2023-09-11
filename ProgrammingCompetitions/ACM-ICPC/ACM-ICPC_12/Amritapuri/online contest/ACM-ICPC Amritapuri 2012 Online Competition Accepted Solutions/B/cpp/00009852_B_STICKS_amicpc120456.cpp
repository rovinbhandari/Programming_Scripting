#include<stdio.h>
#include<math.h>

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
    scanf("%d", &count_testcases);

    int L[50000];
    int A[50000];
    int B[50000];
    int C[50000];

    int M, N;
    int temp;

    int max_len;

    while(count_testcases--)
    {
        scanf("%d %d", &M, &N);

        for(temp=0; temp<M; temp++)
            scanf("%d", &L[temp]);

        quicksort(L, 0, M-1);

        int count = 0;

        for(temp=0; temp<N; temp++)
        {
            scanf("%d %d %d", &A[temp], &B[temp], &C[temp]);


            max_len = sqrt(pow(A[temp], 2)+pow(B[temp], 2)+pow(C[temp], 2));

            while((L[count] <= max_len)&&count<M)
            {
                //printf("fitting: %d\n", L[count]);
                count++;
            }
        }

        printf("%d\n", count);
    }
}
