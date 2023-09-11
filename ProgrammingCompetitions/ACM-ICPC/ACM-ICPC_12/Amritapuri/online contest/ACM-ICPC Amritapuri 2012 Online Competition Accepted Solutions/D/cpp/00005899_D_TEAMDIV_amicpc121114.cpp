#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <cstring>
#include <string>
#include <math.h>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

#define s(x) scanf("%d",&x)
#define sll(x) scanf("%lld",&x)
#define sf(x) scanf("%lf",&x)
#define ss(x) scanf("%s",&x)
#define f(i,a,b) for(int i=a;i<b;i++)
#define fr(i,n)  f(i,0,n)

typedef long long ll;

vector<int> A[20000];


int main(){
	int nt;
	cin>>nt;
	while(nt--){
		int n;
		cin>>n;
		fr(i, n) A[i].clear();
		fr(i, n){
			int k;
			s(k);
			fr(j, k){
				int x;
				s(x);
				A[i].push_back(x);
				A[x].push_back(i);
			}
		}
		
		int cur = 0;
		int seen[20000], color[20000];
		fr(i, n){
			seen[i] = 0;
			color[i] = -1;
		}
		int cyc = 0;
		ll val = 1;
		while(cur < n){
			while(cur < n && seen[cur]) cur++;
			if (cur == n) break;
			queue<int> Q;
			color[cur] = 0;
			Q.push(cur);
			seen[cur] = 1;
			
			while(!Q.empty()){
				int i = Q.front();
				Q.pop();
				//cout<<i<<" : ";
				fr(k, A[i].size()){
					int j = A[i][k];
					if (seen[j] && color[j] != (color[i] + 1)%2){
						//cout<<j<<" problem\n";
						cyc = 1;
						cur = n;
						while (!Q.empty())
						{
							Q.pop();
						}
						break;
					}
					else if(!seen[j]){
						//cout<<j<<" ";
						seen[j] = 1;
						color[j] = (color[i] + 1)%2;
						Q.push(j);
					}
					
				}
				//cout<<endl;
			}
			val =  ((ll)2*val)%1000000007;
		}
		if (cyc) cout<<0<<endl;
		else cout<<val<<endl;
	}
	return 0;
}
