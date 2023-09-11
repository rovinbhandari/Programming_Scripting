#include<cstdio>
#include<iostream>
#include<climits>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>

#define MAX 100000

using namespace std;

long long int sticks[MAX];

int main()
{

    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,M;
        long long int temp;
        scanf("%d %d",&N,&M);
        for(int i=0;i<N;i++)
        {
          scanf("%lld",&sticks[i]);
        }
        long long int max=-1;
        for(int i=0;i<M;i++)
        {
            long long int l,b,h;
            scanf("%lld %lld %lld",&l,&b,&h);
            temp=(long long int)sqrt((l*l)+(b*b)+(h*h));
            if(temp>max)max=temp;
        }
        int count=0;
        //printf("MAX:%lld\n",max);
        for(int i=0;i<N;i++)
        {
            if(sticks[i]<=max)count++;
        }
        printf("%d\n",count);

    }
    return 0;
}
