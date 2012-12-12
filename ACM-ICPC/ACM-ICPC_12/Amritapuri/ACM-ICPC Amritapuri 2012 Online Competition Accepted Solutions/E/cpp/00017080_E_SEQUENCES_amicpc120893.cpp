#include <cstdio>
#include <iostream>
#include <map>
#include <bitset>
#include <vector>
#include <algorithm>
#include <queue>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <set>
#include <ctime>
using namespace std;
 
# define f(i,a,b) for(int i=a;i<b;i++)
# define TT "\t"
# define Clear(x) memset(x,0,sizeof(x))
# define fill(x,a) memset(x,a,sizeof(x))
# define pb push_back
# define mp make_pair
# define X first
# define Y second
# define inf 2147000000
# define linf 9223372036854770000LL
# define sqr(x) ((x)*(x))


typedef unsigned long long ull;
typedef long long ll;
typedef pair<int,int> ii;
typedef vector < pair<int, int > > vii;
typedef vector<int> vi;

template <class T>
inline void ri(T &i){
bool minus=false;
char c;for(c=getchar();(c<'0'||c>'9')&&(c!='-');c=getchar());
if(c=='-'){minus=true;c='0';}
for(i=0;c>='0'&&c<='9';c=getchar())
i=(i<<3)+(i<<1) + (c-48);
if(minus)i=(~i)+1;
}

char a[100005];
int n;
void input(){
	scanf("%d",&n);
	scanf("%s",a);
}

struct node{
	int x[4];
};
node znode;
node tree[300005];
node merge(node b,node c){
	node ret=znode;
		ret.x[0]=b.x[0]+c.x[0];
		
		if(c.x[1]!=0)
		ret.x[1]=b.x[0]+c.x[1];
		
		if(b.x[1]!=0)
		ret.x[1]=max(ret.x[1],b.x[1]+c.x[2]);
		
		if(b.x[0]!=0&&c.x[2]!=0){
			ret.x[1]=max(ret.x[1],b.x[0]+c.x[2]);
		}
		
		ret.x[2]=b.x[2]+c.x[2];
		return ret;
		
	
}
void build_tree(int i,int lo,int hi){
	int mid=(lo+hi)/2;
	if(lo==hi){
		if(a[lo]=='1'){
			tree[i].x[2]=1;
		}
		else{
			tree[i].x[0]=1;
		}
		return ;
	}
	else{
		build_tree(2*i+1,lo,mid);
		build_tree(2*i+2,mid+1,hi);
		tree[i]=merge(tree[2*i+1],tree[2*i+2]);
		
	}
	
	return;
}

node query(int i,int st,int nd, int mi,int ma){
	if(ma<st||mi>nd)return znode;
	if(mi>=st&&ma<=nd){
		return tree[i];
		
	}
	
	int mid=(mi+ma)/2;
	node x= merge(query(2*i+1,st,nd,mi,mid),query(2*i+2,st,nd,mid+1,ma));
	f(i,0,3){
		//cout<<mi<<TT<<ma<<TT<<x.x[i]<<endl;
	}
	return x;
}

int main(){
	int test;cin>>test;
	f(i,0,4)znode.x[i]=0;
	
	while(test--){
		input();
		f(i,0,300005)tree[i]=znode;
		
		build_tree(0,0,n-1);
		int q;
		scanf("%d",&q);
		int st,end;
		f(i,0,q){
			scanf("%d%d",&st,&end);
			node v = query(0,st-1,end-1,0,n-1);
			int tem=0;
			f(i,0,4){
				tem=max(tem,v.x[i]);
			}
			cout<<tem<<endl;
		}
	}
	/*
	f(j,0,5){
	cout<<j<<endl;
	
	f(i,0,3)
	cout<<tree[j].x[i]<<endl;
	cout<<endl;
	}
	*/
	return 0;
}



