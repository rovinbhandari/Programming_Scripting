#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#define pb push_back
#define MAX 1005
#define MAXB 1000006
using namespace std;
vector<int>::iterator it1,it2;
int a[MAX];
int BIT[MAXB];
int read(int idx)
{
    int sum = 0;
    while(idx > 0)
    {
        sum += (BIT[idx]);
        idx -= (idx & -idx);
    }
    return sum;
}
int update(int idx)
{
    while(idx < MAXB)
    {
        BIT[idx]++;
        idx += (idx & -idx);
    }
}
int main()
{
    int t,n,j,i,sum,x,l,h,ans;
    scanf("%d",&t);
    while(t--)
    {
        int sz = 0;
        for(int i=0;i<MAXB;i++)
            BIT[i] = 0;

        scanf("%d %d %d",&n,&l,&h);
        for(i=0;i<n;i++)
            scanf("%d",&a[i]);
        sort(a,a+n);
        ans = 0;
        for(j=n-2;j >=0 ;j--)
        {
            update(a[j+1]);
            sz++;
            for(i=j-1;i>=0;i--)
            {
                sum = a[j] + a[i];
                ans += read(h-sum)-read(l-sum-1);
            }
        }
        printf("%d\n",ans);
    }
    return 0;
}
