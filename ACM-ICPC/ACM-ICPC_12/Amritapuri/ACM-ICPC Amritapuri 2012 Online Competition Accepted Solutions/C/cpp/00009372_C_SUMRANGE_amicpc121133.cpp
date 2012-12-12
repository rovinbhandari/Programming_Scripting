#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int main()
{
    int T;
    int N, L, H;
    vector <int> A;
    long long ans;

    scanf("%d", &T);
    while (T--)
    {
        scanf("%d %d %d", &N, &L, &H);
        A.clear();
        A.resize(N);
        for (int i = 0; i < N; i++)
            scanf("%d", &A[i]);//cout<<A[i]<<' ';}cout<<endl;
        sort(A.begin(), A.end());
        
        ans = 0;

        //cout<<L<<' '<<H<<endl;
        for (int i = 0; i < N; i++)
            for (int j = i+1; j < N; j++)
            {
                //ans += (long long) (upper_bound(&A[j+1], &A[0]+N, H-A[i]-A[j]) - lower_bound(&A[j+1], &A[0]+N, L-A[i]-A[j]));
                
                int l1 = j+1, h1 = N;
                int m1 = (l1+h1)/2;
                while (l1 < h1)
                {
                    if (A[m1] >= L-A[i]-A[j])
                        h1 = m1;
                    else
                        l1 = m1+1;
                    m1 = (l1+h1)/2;
                }
                

                int l2 = j+1, h2 = N;
                int m2 = (l2+h2)/2;
                while (l2 < h2)
                {
                    if (A[m2] > H-A[i]-A[j])
                        h2 = m2;
                    else
                        l2 = m2+1;
                    m2 = (l2+h2)/2;
                }

                ans += (long long)(m2-m1);
                //cout<<L-A[i]-A[j]<<' '<<l1<<' '<<m1<<' '<<h1<<' '<<' '<<H-A[i]-A[j]<<' '<<l2<<' '<<m2<<' '<<h2<<endl;

            }

        printf("%lld\n", ans);

    }

    
}
