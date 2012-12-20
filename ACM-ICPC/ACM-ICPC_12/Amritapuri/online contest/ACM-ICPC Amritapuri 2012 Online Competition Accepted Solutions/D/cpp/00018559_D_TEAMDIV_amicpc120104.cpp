#include<iostream>
#include<map>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
#define mod 1000000007

using namespace std;
int visited[20001];
int colored[20001];
bool discovered[20001];
bool finished;
void bfs(vector<int>g[],int s)
{
	colored[s]=1;
	queue<int> q;
	q.push(s);
	//discovered[start]=true;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		discovered[x]=true;
		for(int i=0;i<g[x].size();++i)
		{
			//cout<<i<<"KKK"<<g[x][i]<<"MMM"<<endl;
			if(discovered[g[x][i]]!=true && colored[g[x][i]]==-1)
			{
				q.push(g[x][i]);
				if(colored[x]==1)
					colored[g[x][i]]=2;
				else if(colored[x]==2)
					colored[g[x][i]]=1;
			}
			else if(discovered[g[x][i]]==true && colored[g[x][i]]==colored[x])
			{
				finished=true;
				//cout<<i<<" "<<x<<endl;
				// return 1;
			}
		}
	}
	// return 0;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,k;
		cin>>n;
		map<pair<int,int>,int> mp;
		vector<int> g[n];
		for(int i=0;i<n;i++)
		{
			cin>>k;
			colored[i]=-1;
			discovered[i]=false;
			for(int j=0;j<k;j++)
			{
				cin>>x;
				int xx=mp[make_pair(i,x)];
				if(xx!=0)
					continue;
				else
				{
					g[i].push_back(x);
					g[x].push_back(i);
					mp[make_pair(x,i)]=1;
				}

			}

		}
		/*for(int i=0;i<n;++i)
		  {
		  for(int j=0;j<g[i].size();++j)
		  cout<<g[i][j]<<" ";
		  cout<<endl;
		  }*/

		finished=false;
		int cnt=0;
		for(int i=0;i<n;++i)
		{
			if(discovered[i]!=true)
			{
				bfs(g,i);
				cnt++;
				if(finished==true)
				{
					break;
				}

			}
		}
		long long int sum=1;
		//cout<<"finished"<<finished<<endl;
		if(finished==true)
		{
			cout<<"0"<<endl;
		}
		else
		{
			for(int i=1;i<=cnt;++i)
			{
				sum=(sum*2)%mod;
			}
			cout<<sum<<endl;
		}
	}
	return 0;
}
