#include<cstdio>
#include<iostream>
# include <stdio.h>
using namespace std;// A utility function to sort an array using Quicksort
void quickSort(int *, int, int);
int count=0;
// returns true if there is triplet with sum equal
// to 'sum' present in A[]. Also, prints the triplet
bool find3Numbers(int A[], int arr_size, int sum,int sum1)
{
    int l, r,k;

    /* Sort the elements */
    quickSort(A, 0, arr_size-1);

    /* Now fix the first element one by one and find the
       other two elements */
    for (int i = 0; i < arr_size - 2; i++)
    {

        // To find the other two elements, start two index variables
        // from two corners of the array and move them toward each
        // other
        l = i + 1; // index of the first element in the remaining elements
        r = arr_size-1; // index of the last element
        k=l;
        while (l<=r)
        {
         if(l<r)
         {

            if (A[i] + A[l] + A[r] < sum)
            l++;
            else if( A[i] + A[l] + A[r] <= sum1)
            {

            count++;
             l++;
            }
            else
            {
             r--;
             l=k;
            }
         }
        else
        {
            r--;
            l=k;
        }
    //    cout<<count<<endl;
    }
    }
 // If we reach here, then no triplet was found
}

/* FOLLOWING 2 FUNCTIONS ARE ONLY FOR SORTING
    PURPOSE */
void exchange(int *a, int *b)
{
    int temp;
    temp = *a;
    *a   = *b;
    *b   = temp;
}

int partition(int A[], int si, int ei)
{
    int x = A[ei];
    int i = (si - 1);
    int j;

    for (j = si; j <= ei - 1; j++)
    {
        if(A[j] <= x)
        {
            i++;
            exchange(&A[i], &A[j]);
        }
    }
    exchange (&A[i + 1], &A[ei]);
    return (i + 1);
}

/* Implementation of Quick Sort
A[] --> Array to be sorted
si  --> Starting index
ei  --> Ending index
*/
void quickSort(int A[], int si, int ei)
{
    int pi;    /* Partitioning index */
    if(si < ei)
    {
        pi = partition(A, si, ei);
        quickSort(A, si, pi - 1);
        quickSort(A, pi + 1, ei);
    }
}

/* Driver program to test above function */
int main()
{
  int test;
  cin>>test;
  while(test--)
  {
      count=0;
    int i,A[1005] ;
    long long int sum,sum2;
    int n;
    cin>>n>>sum>>sum2;
    for(i=0;i<n;i++)
    cin>>A[i];
        find3Numbers(A, n, sum,sum2);
    cout<<count<<"\n";
    //getchar();
 }
 return 0;
}
