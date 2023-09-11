#include<iostream>
#include<list>
#include<queue>
#define MOD 1000000007
using namespace std;
typedef long long int LL;

LL pow_r(LL d,LL n)
{
LL x=1;
while(n>0)
{
if(n&1)
x=(x*d)%MOD;
d=(d*d)%MOD;
n>>=1;
}
return x;
}
class graph
{
    private:
    int v;
    list<int> *adj;
    public:
    graph(){}
    graph(int n)
    {
        v=n;
        adj=new list<int>[v];
    }
    void addedges(int a,int b)
    {
        adj[a].push_back(b);
        adj[b].push_back(a);
    }
    //bfs iterative
    int num_sets()
    {
        bool *visit=new bool[v];
        for(int j=0;j<v;j++)
        visit[j]=false;
        int co=0,k,arr[v],chk=1;
	for(k=0;k<v;k++)
		arr[k]=-1;
        list<int> q;
        list<int>::iterator i;
        for(k=0;k<v;k++)
        {
		
            if(!visit[k])
            {
                co++;//cout<<co<<endl;
		    arr[k]=0;
            q.push_back(k);
            visit[k]=true;
            while(!q.empty())
            {
                int t=q.front();
                q.pop_front();
                for(i=adj[t].begin();i!=adj[t].end();i++)
                {
                    if(!visit[*i])
                    {
			arr[*i]=1-arr[t];
                        q.push_back(*i);
                        visit[*i]=true;
                    }
		    else
		    {
			    if(arr[*i]==arr[t])
			    {
				    chk=0;
			          return 0;
			    }
		    }
                }
            }
            }
        }
     return co;
    }
};
int main()
{
    LL t,n,k,i,j,x;
    LL ans;
    cin>>t;
    while(t--)
    {
        cin>>n;
        graph g(n);
        for(i=0;i<n;i++)
        {
            cin>>k;
            for(j=0;j<k;j++)
            {
                cin>>x;
                g.addedges(i,x);
            }
        }
        k=g.num_sets();
	if(k==0)
		cout<<"0\n";
	else
	{
        ans=pow_r(2,k);
        cout<<ans<<endl;
	}
    }
    return 0;
}