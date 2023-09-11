
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<malloc.h>

int fun(const void *a, const void *b)
{
    const int *aa=a;
    const int *bb=b;
    return *aa-*bb;
}

/*
   int bst(int N,int L, int H, int *arr, int val, int low, int high)
   {
   int small=L-val;
   int large=H-val;
   int middle=(low+high)/2;
   if(arr[mid]>=L)
   {
   count++;
   bst(N,L,H,arr,val,low,mid)

*/

int main()
{
    int test=0;
    scanf("%d",&test);
    int i=0;
    for(i=0;i<test;i++)
    {
        int L=0,N=0,H=0;
        int j=0,k=0,l=0;
        scanf("%d%d%d",&N,&L,&H);
        int *arr;
        arr=(int *)malloc(sizeof(int)*N);
        for(j=0;j<N;j++)
            scanf("%d",&arr[j]);

        int temp=0;
//        qsort(arr,sizeof(arr),sizeof(int),fun);
        for(j=0;j<N;j++)
        {
            for(k=j+1;k<N;k++)
            {
                if(arr[j]>arr[k])
                {
                    temp=arr[k];
                    arr[k]=arr[j];
                    arr[j]=temp;
                }
            }
        }

        int count=0;
        for(j=0;j<N-2;j++)
        {
            if(arr[j]>(H/3)+1)
                break;
            for(k=j+1;k<N-1;k++)
            {
                if(arr[j]+arr[k]>((2*H)/3)+1)
                    break;
                for(l=k+1;l<N;l++)
                {
                    if(arr[j]+arr[k]+arr[l]>H)
                        break;
                    if(arr[j]+arr[k]+arr[l]>=L && arr[j]+arr[k]+arr[l]<=H)
                        count++;
                }
            }
        }
        printf("%d\n",count);
    }
    return 0;
}
