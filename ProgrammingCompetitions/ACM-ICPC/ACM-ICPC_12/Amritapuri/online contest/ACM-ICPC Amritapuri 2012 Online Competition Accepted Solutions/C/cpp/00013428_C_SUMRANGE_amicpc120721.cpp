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
int bisearch1(int *A,int low,int high,int key)
{
    while(low < high)
    {
        int mid = low + (high-low)/2;
        if(A[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
int bisearch2(int *A,int low,int high,int key)
{
    while(low < high)
    {
        int mid = low + (high-low)/2;
        if(A[mid] > key)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return low;
}
int main()
{
    //freopen("input.txt","r",stdin);
    int N,T,L,H,result;
    scanf("%d",&T);
    for(int test = 1;test <= T;test++)
    {
        result = 0;
        scanf("%d%d%d",&N,&L,&H);
        int *A = new int[N];
        //int *B = new int[N];
        for(int i = 0;i < N;i++)
        {
            scanf("%d",&A[i]);
            //B[i] = A[i];
        }
        sort(A,A+N);
        for(int i = 0;i < N-2;i++)
        {
            for(int j = i + 1;j < N-1;j++)
            {
                int flag  = 0;
                int key1 = L - A[i] - A[j];
                int key2 = H - A[i] - A[j];
                int a = bisearch1(A,j+1,N-1,key1);
                int b = bisearch2(A,j+1,N-1,key2);
                //printf("%d %d\n",a,b);
                if(A[a] >= key1)
                {
                    if(a-1 > j)
                    {
                        if(A[a-1] >= key1)
                        {
                            a--;
                        }
                    }
                }
                else if(A[a+1]>=key1)
                {
                    a++;
                }
                else
                    flag  = 1;
                if(A[b] <= key2)
                {
                    if(b+1 <= N-1)
                    {
                        if(A[b+1] <= key2)
                        b++;
                    }
                }
                else if(A[b-1]<=key2)
                {
                    b--;
                }
                else
                    flag = 1;
                if(a == j)
                    a++;
                if((b >= a) && (flag == 0))
                result += b-a+1;
            }
        }
        printf("%d\n",result);
    }
    return 0;
}
