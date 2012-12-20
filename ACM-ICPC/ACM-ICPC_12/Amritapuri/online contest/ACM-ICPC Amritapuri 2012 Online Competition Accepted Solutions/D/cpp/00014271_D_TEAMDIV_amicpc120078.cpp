
/* -.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.-.
_ Problem :
_._._._._._._._._._._._._._._._._._._._._.*/

#include<algorithm>
#include<assert.h>
#include<bitset>
#include<climits>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<deque>
#include<iostream>
#include<map>
#include<memory.h>
#include<queue>
#include<set>
#include<sstream>
#include<stack>
#include<string>
#include<utility>
#include<vector>

using namespace std;

vector<int>E;

int next_edge[200001],to[200001],last_edge[20001];
int vis[20001];
long long int M = 1000000007;

void init(int n){
	for(int i=1;i<=n;i++){
		vis[i] = 0;
		last_edge[i] = -1;
	}
}

long long int power(long long int n){
	long long int temp;
	if(n == 0)
		return 1;
	temp = power(n/2);
	if(n%2)
		return (((2*temp)%M)*temp)%M;
	else
		return (temp*temp)%M;
}

int main()
{
                int t,edge_no,flag,node;
		cin>>t;
		while(t--)
		{
			flag = 1;
			edge_no = 0;
			int n;
			long long int count;
			cin >> n;
			init(n);
			count = 0;
			for(int i=1;i<=n;i++)
			{
                             int x;
			     cin>>x;
			     for(int j = 0;j<x;j++){
				     cin >> node;
				     to[++edge_no] = node+1;
				     next_edge[edge_no] = last_edge[i];
				     last_edge[i] = edge_no;
				     to[++edge_no] = i;
				     next_edge[edge_no] = last_edge[node+1];
				     last_edge[node+1] = edge_no;
			     }
			}
			for(int i=1;i<=n;i++){
				if(!vis[i]){
					count++;
					queue<int> q;
					q.push(i);
					vis[i]=1;
					while(!q.empty()){
						int vertex = q.front();
						q.pop();
						for(int temp=last_edge[vertex];temp!=-1;temp=next_edge[temp]){
							if(vis[to[temp]] == vis[vertex]){
								flag = 0;
							}
							else if(!vis[to[temp]]){
								if(vis[vertex] == 1)
									vis[to[temp]] = 2;
								else
									vis[to[temp]] = 1;
								q.push(to[temp]);
							}
						}
						if(!flag) break;
					}
					if(!flag)
						break;
				}
			}
			if(!flag)
				cout << 0 << endl;
			else
				cout << power(count) << endl;
		}
	        return 0;
}
