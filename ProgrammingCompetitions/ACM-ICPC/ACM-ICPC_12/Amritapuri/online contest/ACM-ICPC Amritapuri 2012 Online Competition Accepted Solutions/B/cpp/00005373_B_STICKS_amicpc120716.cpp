#include<iostream>
#include<stdio.h>
#include<string.h>
#include<math.h>

using namespace std;

int main()
{
    int no_of_test, i , N, M, count,j,MAX;
    int L[50001], A[50001], B[50001], C[50001], Max[50001];

    cin>>no_of_test;
    while(no_of_test--)
    {
        cin>>N>>M;
        count = 0;
        MAX=0;
        for(i=0;i<N;i++)
        {
            cin>>L[i];
        }
        for(i=0;i<M;i++)
        {
            cin>>A[i]>>B[i]>>C[i];
            Max[i] = sqrt(pow(A[i],2)+(pow(B[i],2))+(pow(C[i],2)));
            if(MAX<Max[i])
            {
                MAX = Max[i];
            }
        }
        for(i=0;i<N;i++)
        {
            if(L[i]<=MAX)
            {
                count++;
            }
        }
        cout<<count<<"\n";
    }
    return 0;
}
