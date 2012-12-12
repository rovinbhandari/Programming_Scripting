#include<stdio.h>
#include<vector>
using namespace std;
#define LL long long
#define MOD 1000000007
vector<int> lists[20005];
bool marked[20005];
bool decided[20005];
int N;
bool dfs(int node,bool mark)
{
    if(marked[node])
        {
                if(decided[node]==mark)
                        return true;
                return false;
        }
        marked[node]=1;
        decided[node]=mark;
        int size=(int)lists[node].size();
    bool res=1;
        for(int i=0;i<size;i++)
        {
                if(res)res=dfs(lists[node][i],!mark);
                else break;
        }
        return res;
}
void init()
{
        for(int i=0;i<N;i++)
        {
                lists[i].clear();
                marked[i]=0;
                decided[i]=0;
        }
}
int main()
{
        int t;
        scanf("%d",&t);
        while(t--)
        {
                scanf("%d",&N);
        init();
                for(int i=0;i<N;i++)
                {
                        int rivals;
                        scanf("%d",&rivals);
                        for(int j=0;j<rivals;j++)
                        {
                                int rival;
                                scanf("%d",&rival);
                                lists[i].push_back(rival);
                                lists[rival].push_back(i);
                        }
                }
                LL res=1;
                for(int i=0;i<N;i++)
                {
                        if(marked[i])continue;
                        if(dfs(i,1))res*=2;
                        else {res=0;break;}
                        res%=MOD;
                }
                printf("%lld\n",res);
        }return 0;
}