#include<iostream>
#include<cstdlib>
#include<vector>
#include<climits>
#include<cctype>
#include<map>
#include<list>
#include<cstdio>
#include<algorithm>
#include<memory.h>
#include<cmath>
#include<queue>
#include<fstream>
#include<sstream>
#include<set>
#include<iomanip>
#include<bitset>
#include<ctime>
#define L long long int
#define LD long double
#define pi 3.141592653589793238462643383
#define M 1000000007

using namespace std;

int vis[200005];
vector<int> g[200005];
map<pair<int,int>, int >  mp;

int lev[1000000];
int myvis[1000000];
bool isnb = 0;
void is_bip(int i, int l){
	int nl;
	if(l == 1){
		nl = 2;
	}
	else {
		nl = 1;
	}
//	cout << "\nVis " << i << " " << lev[i] << " " << nl;

	if ( myvis[i] == 1 || isnb == 1 ) {
		if(lev[i] != nl){
			isnb = 1;
		}
		return;
	}
	myvis[i] = 1;
	lev[i] = nl;
	for(int j = 0; j < g[i].size(); j++){
//		cout << "\n\tvisiting " << g[i][j] << " for " << i << endl;
		is_bip( g[i][j], nl);
	}
}

void dfs(int v)
{
	if(vis[v]==1)
		return;
	vis[v]=1;

	for(int i=0;i<g[v].size();i++)
	{
		dfs(g[v][i]);
	}
}

L power(int n)
{
	if(n==0)
		return 1;

	L t=power(n/2);

	if(n%2==1)
		return (t*t*2)%M;
	else
		return (t*t)%M;
}

int main()
{
	int t=100,n,i,j,k,c, x;
	L ans;
	cin >> t;
	while(t--)
	{
		mp.clear();
		cin>>n;
		for(i=0;i<n;i++)
		{
			vis[i]=0;
			myvis[i] = 0;
			lev[i] = 0;
			g[i].clear();
		}
		for(i=0;i<n;i++)
		{
			cin>>k;
			for(j=0;j<k;j++) 
			{
				
				cin >> x;
				int tmp = i;
				if(tmp > x){
					swap(tmp,x);
				}

				if ( mp[pair<int,int>(tmp,x)]==1 ) {
					continue;
				}


				g[tmp].push_back(x);
				g[x].push_back(tmp);

				mp[pair<int,int>(tmp,x)]=1;
				//pr1.first = i;
				//pr1.second = x;

			}

		}

/*		for(i = 0; i < n; i++){
			cout << i << "\t :";
			for(j = 0; j< g[i].size(); j++ ){
				cout << g[i][j] << " ";
			}
			cout << endl;
		}
*/
		c=0;
		bool flg = 0;
		for(i=0;i<n;i++)
		{
			if(vis[i]==0)
			{
				isnb = 0;
				is_bip(i,1);
				if(isnb == 1){
					flg = 1;
					break;
				}
				dfs(i);
				c++;
			}
		}

		
//		cout << endl << c << endl;
		if(flg == 0)
		{
			ans=power(c);
			cout<<ans<<"\n";  
		}
		else
		{
			cout<<"0\n";
		}

	}
	return 0;
}
