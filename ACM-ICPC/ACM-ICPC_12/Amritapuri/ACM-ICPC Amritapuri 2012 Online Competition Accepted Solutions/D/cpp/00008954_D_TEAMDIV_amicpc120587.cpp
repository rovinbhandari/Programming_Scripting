#include<iostream>
#include<vector>
#include<string.h>
#include<map>
#include<algorithm>
#include<cmath>
#include<stdio.h>
#include<set>
#include<utility>
#include<stack>
#include<cmath>
#include<cassert>
#include<queue>
using namespace std;

#define MOD 1000000007
#define INF  2147483647

vector<int> v[20011];
int a[20011];
int t,n,p,x;
bool g;

void dfs(int i,int j){
	queue<int> q;
	q.push(i);
	a[i]=1;
	while(!q.empty()){
		int m=q.front();
		q.pop();
		for(int j=0;j<v[m].size();j++){
			int l=v[m][j];
			if(a[l]==0){
				q.push(l);
				if(a[m]==1)
					a[l]=2;
				else
					a[l]=1;
			}
			else if(a[l]!=0 && a[l]==a[m]){
				g=false;
				break;
			}
		}
	}
}
			
	

long long int pp(int a){
	if(a==0)
		return 1;
	long long int b=pp(a/2);
	b=(b*b)%MOD;
	if(a%2==1)
		b=(2*b)%MOD;
	return b;
}

int main(){
	cin>>t;
	while(t--){
		cin>>n;
		g=true;
		for(int i=0;i<20011;i++)
		v[i].clear();
		for(int i=0;i<n;i++){
			cin>>x;
			while(x--){
				cin>>p;
				v[i].push_back(p);
				v[p].push_back(i);
			}
		}
		memset(a,0,sizeof(a));
		int ct=0;
		for(int i=0;i<n;i++){
			if(a[i]==0){
				dfs(i,1);
				ct++;
			}
		}
		long long int l=pp(ct);
		if(g)
		cout<<l<<endl;
		else
		cout<<"0"<<endl;
	}
	return 0;
}
