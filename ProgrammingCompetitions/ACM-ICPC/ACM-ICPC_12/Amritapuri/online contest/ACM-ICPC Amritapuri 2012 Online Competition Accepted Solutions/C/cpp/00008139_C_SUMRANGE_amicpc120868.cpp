#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;

int main()
{
    int test;
    scanf("%d",&test);
    while(test--)
    {
    int N,L,H;
    scanf("%d %d %d",&N,&L,&H);
    int *A=new int[N];
    for(int i=0;i<N;i++)
        scanf("%d",&A[i]);
    sort(A,A+N);
    int l,r,newL;
    int count1=0,count2=0;
    for (int i = 0; i < N - 2; i++)
    {
        l = i + 1; // index of the first element in the remaining elements
        r = N-1; // index of the last element
        while (l < r)
        {
            if( A[i] + A[l] + A[r] >= L && A[i] + A[l] + A[r] <= H)
            {
                //cout << i<<"\t"<<l<<"\t"<<r<<endl;
                count1++;
                newL=l+1;
                while(newL<r)
                {
                     if( A[i] + A[newL] + A[r] >= L && A[i] + A[newL] + A[r] <= H)
                     {
                         count1++;
                         newL++;
                     }
                     else
                        break;
                }
                r--;
            }
            else if(A[i] + A[l] + A[r] > H)
                r--;
            else
                l++;
        }
    }

   /* for (int i = 0; i < N - 2; i++)
    {
        l = i + 1; // index of the first element in the remaining elements
        r = N-1; // index of the last element
        while (l < r)
        {
            if( A[i] + A[l] + A[r] <= H)
            {
                cout << A[i]<<"\t"<< A[l]<<"\t"<< A[r]<<endl;
                cout << count2<<endl;
                count2+=r-l+1;
                l++;
            }
            else // A[i] + A[l] + A[r] > sum
                r--;
        }
    }

    cout << min(count1,count2)<<endl;
*/
    cout << count1<<endl;
    }
    return 0;
}
