#include <vector>
#include <list>
#include <queue>
#include <map>
#include <set>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

long long modPow(long long base,long long  exp,long long  mod) {
	long long res = 1;
	while (exp) {
		if (exp&1) res = (res*base)%mod;
		exp>>=1;
		base = (base*base)%mod;
	}
	return res;
}

bool bfs(vector<vector< int> > g, vector<bool> &visited,vector<int> &depth, int index){
	queue<int> Q;
	Q.push(index);
	visited[index] = 1;
	depth[index] = 0;
	int node, adjNode;

	while(!Q.empty()) {
		node = Q.front(); Q.pop();
		for(int i=0; i<g[node].size(); i++) {
			adjNode = g[node][i];

			if(depth[adjNode] == depth[node]) {
				return false;
			}

			if(visited[adjNode] == false) {
				depth[adjNode] = depth[node] + 1;
				Q.push(adjNode);
				visited[adjNode] = true;
			}

		}
	}
	return true;
}

int main(){
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;

		vector<vector <int> > g(n,vector<int> () );

		for (int i = 0; i < n; i++) {
			int rival;
			cin>>rival;
			for (int j = 0; j < rival; j++){
				int temp;
				cin>>temp;
				g[i].push_back(temp);
				g[temp].push_back(i); // to make the graph undirected

			}
		}

		vector<bool> visited(n,false);
		vector<int> depth(n,-1);

		int count = 0; bool possible = true;
		for (int i = 0; i < n; i++) {
			if(visited[i] == false){
				count++;
				if(bfs(g,visited,depth,i) == false) {
					possible = false;
					break;
				}

			}
		}
	if(possible == false) cout << 0 << endl;
	else
		cout<<modPow(2,count,1000000007)<<endl;

	}
}
