#include<cstdio>
#include<algorithm>
using namespace std;

#define MXL 17
#define MXT (1<<17)

const int mxt = MXT;
int tree[2*MXT+10][3], n;
// 0 - 0's
// 1 - 0..1
// 2 - 1..1

char st[100010];

void initTree(){
	int i;
	for (i=mxt;i<mxt+n;i++){
		tree[i][0] = tree[i][1] = tree[i][2] = 0;
		if (st[i-mxt]=='0')
			tree[i][0] = 1;
		else
			tree[i][2] = 1;
	}
	for (i=mxt-1;i>0;i--){
		tree[i][0] = tree[2*i][0] + tree[2*i+1][0];
		tree[i][2] = tree[2*i][2] + tree[2*i+1][2];
		tree[i][1] = max(tree[2*i][0]+tree[2*i+1][1], max(tree[2*i][0]+tree[2*i+1][2], tree[2*i][1] + tree[2*i+1][2]));
	}
}

int query1(int a,int b){
	if (a==b)
		return 1;
	int x;
	int lnode, rnode, l[3], r[3], p[3];
	lnode = mxt+a;
	rnode = mxt+b;
	for (int i=0;i<3;i++){
		l[i] = tree[lnode][i];
		r[i] = tree[rnode][i];
	}
	while (lnode != rnode){
		//printf("ln:%d rn:%d\n",lnode,rnode);
		if ( ((lnode&1)==0)  && (lnode+1 != rnode) ) {
			p[0] = l[0] + tree[lnode+1][0];
			p[2] = l[2] + tree[lnode+1][2];
			p[1] = max(l[0]+tree[lnode+1][1], max(l[0]+tree[lnode+1][2], l[1] + tree[lnode+1][2]));
			l[0] = p[0]; l[1] = p[1]; l[2] = p[2];
		}
		if ( ((rnode&1)==1)  && (lnode+1 != rnode) ) {
			p[0] = tree[rnode-1][0] + r[0];
			p[2] = tree[rnode-1][2] + r[2];
			p[1] = max(tree[rnode-1][0]+r[1], max(tree[rnode-1][0]+r[2], tree[rnode-1][1] + r[2]));
			r[0] = p[0]; r[1] = p[1]; r[2] = p[2];
		}
		lnode >>= 1;
		rnode >>= 1;
		//printf("l0:%d l1:%d l2:%d r0:%d r1:%d r2:%d\n",l[0],l[1],l[2],r[0],r[1],r[2]);
	}
	p[0] = l[0] + r[0];
	p[2] = l[2] + r[2];
	p[1] = max(l[0]+r[1], max(l[0]+r[2], l[1] + r[2]));
	return max(p[0], max(p[1], p[2]));
}

int main(){
	int t,q,a,b;
	scanf("%d",&t);
	while (t--){
		scanf("%d%s%d",&n,st,&q);
		initTree();
		while(q--){
			scanf("%d%d",&a,&b);
			printf("%d\n",query1(a-1,b-1));
		}
	}
	return 0;
}
