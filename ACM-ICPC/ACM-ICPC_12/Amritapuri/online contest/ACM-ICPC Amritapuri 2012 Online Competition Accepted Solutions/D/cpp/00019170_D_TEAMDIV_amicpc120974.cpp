#include <algorithm>
#include <vector>
#include <cstdio>
#include <list>
#include<cstring>
using namespace std;
int status[20010],cnt;
bool flag;

#define MOD 1000000007LL
typedef unsigned long long ull;
ull pow(int n,int k)
{
    ull res;
    if(k==0LL)return 1LL;
    res=pow(n,k/2LL);
    res=(res*res)%MOD;
    if(k&1LL)
           return (n*res)%MOD;
    return res;
}


void dfs(const vector< vector<int> > &v,int n,int x,int col)
{
    status[x]=col;
//    printf("size:%d\n",v[x].size());
        for(int i=0; i<(int)v[x].size(); i++)
    {
  //      printf("dfs:: %d %d %d\n",i,v[x][i],status[v[x][i]]);
        if(status[v[x][i]]==col)
        flag = false;
        else if(!status[v[x][i]] && col==1)
            dfs(v,n,v[x][i],2);
        else if(!status[v[x][i]] && col==2)
        {
            dfs(v,n,v[x][i],1);
        }
    }

}

void odd_cycle(const vector< vector<int> > &v,int n)
{
    int i;
    for(i=0; i<n; i++)
        if(status[i]==0)
            {dfs(v,n,i,1);cnt++;}

}

int main()
{
    int t, n, i,j, k, x;
    scanf("%d", &t);
    vector< vector<int> > v;
    vector<int> tv;

    while (t--)
    {
        scanf("%d", &n);
        memset(status,0,sizeof status);
        v.clear();
        for (i = 0; i < n; i++)
        {
            scanf("%d", &k);
            tv.clear();
            for (j = 0; j < k; j++)
            {
                scanf("%d", &x);
                tv.push_back(x);
            }
            v.push_back(tv);
        }
        for(i=0;i<n;i++)
        {

            for(j=0;j<v[i].size();j++)
            {
                    v[v[i][j]].push_back(i);
            }
        }

        flag=true;cnt=0;
        odd_cycle(v,n);
      //  printf("%d %d\n",flag,cnt);
        if(!flag)printf("0\n");
        else
        {

            //j=kruskal(v,n);

            printf("%lld\n",pow(2,cnt));
        }

    }

return 0;
}
