#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
#include<stdio.h>
using namespace std;

#define ll int
struct data{
	ll sum;
	ll ans;
	ll n0;
	ll n1;
};

string arr;
data tree[500000];

int zc[500000];
int oc[500000];

// Fast Input

int sign;

int ch;

inline void S( int &x ) {
	x=0;
	while((ch<'0' || ch>'9') && ch!='-' && ch!=EOF) ch=getchar_unlocked();
	if (ch=='-')
		sign=-1 , ch=getchar_unlocked();
	else
		sign=1;
	do
		x=(x<<3)+(x<<1)+ch-'0';
	while((ch=getchar_unlocked())>='0' && ch<='9');
	x*=sign;
}

inline ll mymax(ll a,ll b, ll c){
	if(a>b&&a>c)
		return a;
	if(b>c)
		return b;
	return c;
}

void construct(int node,int b,int e)
{
	if(b==e)
	{
		tree[node].sum=1;
		tree[node].ans=1;
		//		cout << node << "\t" << tree[node].maxsum << endl;
	//	if(){
	//	}
		if(arr[b] == '0'){

			tree[node].n0=1;
			tree[node].n1=0;
		}
		else{
			tree[node].n0=0;
			tree[node].n1=1;
		}
		return;
	}
	int mid=(b+e)/2;
	construct(2*node,b,mid);
	construct(2*node+1,mid+1,e);

	tree[node].sum= tree[2*node].sum + tree[2*node+1].sum; //We can doo watever operation we want
	tree[node].ans = max(tree[2*node].ans + tree[2*node +1].n1, mymax(tree[2*node].n0 + tree[2*node +1].ans, tree[2*node].n0+tree[2*node+1].n0,  tree[2*node].n1+tree[2*node+1].n1));

	tree[node].n0 = tree[2*node].n0 + tree[2*node+1].n0;
	tree[node].n1 = tree[2*node].n1 + tree[2*node+1].n1;
}

void update( int ){
}

data* query(int node,int b,int e,int i,int j) {
	if(i>e || j<b) return NULL;

	if(b>=i && e<=j) return &tree[node];

	int mid=(b+e)/2;
	data *x=query(2*node,b,mid,i,j);
	data *y=query(2*node+1,mid+1,e,i,j);

	if(x == NULL)
		return y;
	if(y == NULL)
		return x;

	data *d = new data;
	d->sum= x->sum + y->sum; //We can doo watever operation we want
	d->ans = max(x->ans + y -> n1, mymax(x -> n0 + y->ans, x -> n0 + y -> n0, x->n1 + y -> n1));
	d->n0 = x -> n0 + y->n0;
	d->n1 = x->n1 + y->n1;
	//	*d = mymax(tree[*x].maxsum, tree[*y].maxsum, tree[*x].maxs+tree[*y].maxp);;
	return d;
}

int main()
{
	int n,t,q;

	cin >> t;

	while(t--){

		//scanf("%d%d",&n,&t);
		cin >> n;



		int i,j,count=0,k;


		cin >> arr;
/*
		if(arr[0] == '0'){
			zc[0] = 1;
			oc[0] = 0;
		}	
		else{
			zc[0] = 0 ;
			oc[0] = 1;
		}

		for(i = 1; i < n; i++ ) {
			if(arr[i] == '0'){
				zc[i] = zc[i-1] + 1;
				oc[i] = oc[i-1];
			}	
			else{
				zc[i] = zc[i-1] ;
				oc[i] = oc[i-1]+1;

			}
		}
*/
		construct(1,0,n-1);
		//	for(i = 1; i < 2*pow(2, log10(n)/log10(2)+1); i++){
		//		cout << i << "\t" << tree[i].maxsum << endl;
		//	}
//		S(q);
		cin >> q;

		for(i=0;i<q;i++)
		{
			int x,y;
			//	scanf("%d%d",&x,&y);
			//S(x);
			//S(y);
			cin >> x >> y;
			data* k = query(1,0,n-1,x-1,y-1);
			//cout << k->maxsum << endl;
			printf("%d\n",k->ans);
		}
	}
	//printf("%d\n",count);
}


