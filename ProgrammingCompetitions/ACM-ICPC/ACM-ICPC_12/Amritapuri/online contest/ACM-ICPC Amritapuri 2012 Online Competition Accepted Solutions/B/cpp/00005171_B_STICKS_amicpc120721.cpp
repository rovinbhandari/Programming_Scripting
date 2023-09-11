# include <iostream>
# include <fstream>
# include <sstream>
# include <iomanip>
# include <algorithm>
# include <numeric>
# include <cstdio>
# include <cmath>
# include <cstdlib>
# include <cstring>
# include <vector>
# include <list>
# include <set>
# include <map>
# include <stack>
# include <queue>
# include <deque>
using namespace std;
typedef unsigned long long int ulli;
int main()
{
    //freopen("input.txt","r",stdin);
    long long int N,M,T,temp,max,result;
    long long int B,D,C;
    scanf("%lld",&T);
    for(long long int test = 1;test <= T;test++)
    {
        temp = 0;
        max  = 0;
        result = 0;
        long long int value = 0;
        scanf("%lld%lld",&N,&M);
        long long int *A = new long long int[N];
        for(long long int i = 0;i < N;i++)
            scanf("%lld",&A[i]);
        for(long long int i = 0;i < M;i++)
        {
            scanf("%lld%lld%lld",&B,&C,&D);
            temp = (B*B) + (C*C) + (D*D);
        //printf("   %lld   ",temp);
        if(max < temp)
            {
                max = temp;
            }
        }
        //printf("   %lld   ",max);
        value = (long long int)floor(sqrt(max));
        for(long long int i = 0;i < N;i++)
        {
            if(A[i] <= value)
                result++;
        }
        printf("%lld\n",result);
    }
    return 0;
}
