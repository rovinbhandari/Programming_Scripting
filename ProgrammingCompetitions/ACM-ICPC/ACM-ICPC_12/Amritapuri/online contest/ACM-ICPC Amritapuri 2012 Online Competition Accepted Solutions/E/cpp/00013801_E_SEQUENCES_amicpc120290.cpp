#include <vector>
#include <string>
#include <list>
#include <map>
#include <set>
#include <deque>
#include <queue>
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
#include <cstring>
#include <ctype.h>
#include <bitset>
#include <assert.h>

using namespace std;

#define REP(i, n) for(int i=0; i<(n); i++)
#define FOR(i, a, b) for(int i=(a); i<(b); i++)
#define IFOR(i, a, b) for(int i=(a); i>=(b); i--)
#define FORD(i, a, b, c) for(int i=(a); i<(b); i+=(c))

#define SS ({int x;scanf("%d", &x);x;})
#define SI(x) ((int)x.size())
#define PB(x) push_back(x)
#define MP(a,b) make_pair(a, b)
#define SORT(a) sort(a.begin(),a.end())
#define ITER(it,a) for(typeof(a.begin()) it = a.begin(); it!=a.end(); it++)
#define ALL(a) a.begin(),a.end()
#define INF 1000000000
#define V vector
#define S string
#define FST first
#define SEC second
typedef V<int> VI;
typedef V<S> VS;
typedef long long LL;
typedef pair<int, int> PII;
/// pre code ends:

struct T{

    int ms;
int x,y,z;
	
	
} tree[1000005];
int k=0;

int p[100005];
char xyz[100005];




void build(int node, int a, int b){
	if(a==b){
		tree[node].ms  = 1;
		tree[node].x=(p[a]==0)?1:0;
		tree[node].y=0;
		tree[node].z=(p[a]==1)?1:0;
	
		return;
	}
	int mid = (a+b)/2;
	build(2*node, a, mid);
	build(2*node+1, mid+1, b);
	
		
		tree[node].x  = tree[2*node].x+tree[2*node+1].x;
		tree[node].y=max(max(tree[2*node].x+tree[2*node+1].y , tree[2*node].y+tree[2*node+1].z),tree[2*node].x+tree[2*node+1].z);
		tree[node].z=tree[2*node].z+tree[2*node+1].z;
		tree[node].ms  =max(max(tree[node].x,tree[node].y),tree[node].z);
			
	
		//cout<<tree[node].ms<<"  "<<node<<endl;
}

/*void upd(int node){
                   if(node<1)
                             return ;
                   tree[node].s = (tree[2*node].s+tree[2*node+1].s);
	               tree[node].L = max(tree[2*node].L,tree[2*node].s+tree[2*node+1].L);
	               tree[node].R = max(tree[2*node+1].R,tree[2*node+1].s+tree[2*node].R);
	               tree[node].ms = max(tree[2*node].R+tree[2*node+1].L, max(tree[2*node].ms,tree[2*node+1].ms));
	               upd(node/2);
	               
}


void update(int node,int val){
                             
		                      tree[node].s  = val;
		                      tree[node].ms  = val;
		                      tree[node].L=val;
		                      tree[node].R=val;
		                      
		                      upd(node/2);
		                      
		                      
}
*/


T  query(int node, int a, int b, int i,int j){

	if(i<=a && j>=b){
		return tree[node];
	}
	int mid = (a+b)/2;

	if(j<=mid){
		return query(2*node, a, mid, i, j);
	}
	else if(i>mid){
		return query(2*node+1, mid+1, b, i, j);
	}
	else{
		T p1, p2, p3;
		p1 = query(2*node, a, mid, i, j);
		p2 = query(2*node+1, mid+1, b, i, j);
		/*p3.s=(p1.s+p2.s);
		p3.R=max(p2.R,p2.s+p1.R);
		p3.L=max(p1.L,p1.s+p2.L);
		p3.ms = max(max(p1.ms, p2.ms), p1.R+p2.L); */
		
			p3.x  = p1.x+p2.x;
		p3.y=max(max(p1.x+p2.y , p1.y+p2.z),p1.x+p2.z);
		p3.z=p1.z+p2.z;
		p3.ms  =max(max(p3.x,p3.y),p3.z);
		///cout<<p3.ms<<endl;
		return p3;
	}


}

int main(){
    
    int t=SS;
    while(t--)
    {
	int n=SS;

	
 scanf("%s",xyz);
 for(int i=0;i<n;i++)
 p[i]=xyz[i]-'0';
 
	build(1, 0, n-1);
  
	int q=SS;
	getchar();
	
	while(q--){//cout<<q<<"q"<<endl;
               
               
		int  a=SS, b=SS;
		getchar();
		
		        printf("%d\n", query(1, 0, n-1, a-1, b-1).ms);
        
        

	}
   }

	return 0;
}

/*

5
1 2 3 4 5
6
U 1 6
Q 1 5
U 1 7
Q 1 5

*/


