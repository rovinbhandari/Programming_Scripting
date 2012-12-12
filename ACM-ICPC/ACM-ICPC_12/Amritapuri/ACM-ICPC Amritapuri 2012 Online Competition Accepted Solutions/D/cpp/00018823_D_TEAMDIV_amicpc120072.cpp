#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<stack>
#include<queue>
#include<algorithm>

using namespace std;
#define MOD 1000000007
int color[20010], n;
vector<vector<int> > graph;
int t;

int dfs(int v, int c) {
	if(color[v] == c) return 1;
	if(color[v] == -c) return -1;
	color[v] = c;
	int node;
	for(int i = 0; i < (int) graph[v].size(); i++) {
		node = graph[v][i];
		if(dfs(node,-c)==-1) return -1;
	}
	return 1;
}

unsigned long long int my_pow(int p) {
	if(p < 1) return 1;
	unsigned long long int ans = my_pow(p/2)%MOD;
	ans = (ans*ans)%MOD;
	if(p%2==1) ans = (ans*2)%MOD;
	return ans;
}

int main()
{
	int j, i, t1, cc, res, T;
	cin>>T;
	vector<int> temp;
	vector<int> tmv;
	for(t = 1; t <= T; t++) {
		cc = 0;
		res = 0;
		cin>>n;
		graph.clear();
		tmv.clear();
		for(i =0 ; i < n; i++) graph.push_back(tmv);
		for(i= 0; i<n; i++)
		{
			cin>>j;
			for(int k= 0; k<j; k++)
			{
				cin>>t1;
			//	temp.push_back(t1);
				graph[i].push_back(t1);
				graph[t1].push_back(i);
				//graph[i][t1] = graph[t1][i] = t;
			}
//			graph.push_back(temp);
		}
		for(i=0; i<n; i++)
		{
			if(color[i] != t && color[i] != -t)
			{
				cc ++;
				res = dfs(i, t);
			}
			if(res == -1)
				break;
		}
		if(res == -1)
			cout<<0<<endl;
		else
			cout<<my_pow(cc)<<endl;
	}
	return 0;
}
