/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)
#include<set>

using namespace std;
int mod = 1000000007;
long long pow_2(int n)
{
    long long foo = 2;
    long long ans = 1;
    while(n>0)
    {
        if((n&1)>0)
        ans = (ans*foo)%mod;
        n>>=1;
        foo=(foo*foo)%mod;
    }
    return ans%mod;
}
int main()
{
    in_T
    {
        int n,k,foo;
        in_I(n);
        set<int> neigh[n];
        set<int>::iterator it;
        for(int i=0;i<n;i++)
        {
            in_I(k);
            while(k--)
            {
                in_I(foo);
                neigh[i].insert(foo);
                neigh[foo].insert(i);
            }
        }
        int visited[n];
        for(int i=0;i<n;i++)
            visited[i] = 0;
        int num = 0;
        for(int i=0;i<n;i++)
        {
            if(visited[i]==0)
            {
                num++;
                visited[i] = 1;
                queue<int> BFS;
                BFS.push(i);
                while(!BFS.empty())
                {
                    foo = BFS.front();
                    BFS.pop();
                    for(it =neigh[foo].begin();it!=neigh[foo].end();it++)
                    {
                        if(visited[*it]==0)
                        {
                            visited[*it] = -visited[foo];
                            BFS.push(*it);
                        }else if(visited[*it] == visited[foo])
                        {
                            num = 0;
                            i = n;
                            while(!BFS.empty())
                            BFS.pop();
                            break;
                        }
                    }
                }
            }
        }
		if( num == 0 ) 
		cout << 0 << endl ; 
		else
        cout<<pow_2(num)<<endl;
    }
}
