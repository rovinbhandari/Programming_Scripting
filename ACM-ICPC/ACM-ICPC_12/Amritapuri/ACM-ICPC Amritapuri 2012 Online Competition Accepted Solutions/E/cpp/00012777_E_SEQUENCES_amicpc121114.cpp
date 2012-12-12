#include <vector>
#include <queue>
#include <deque>
#include <map>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
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


/*PROBLEM CODE STARTS HERE -- CHANGE THIS*/
#define SIZE_LIM 320000
#define DEBUG 0
#define NFLAGS 2

void swap(int &a, int &b){
    int c = a;
    a = b;
    b = c;
}

char str[SIZE_LIM];

class data{
	public:
	int a0, a1, a;
	// declare variables
     
    data(){	// initialize
		a0 = a1 = a = 0;
	}
	
    void input(int i1){ // input from STDIN
		int i = str[i1] - '0';
		a0 = (i == 0);
		a1 = (i == 1);
		a = 0;
	}
		
	void copy(const data & d){	// copy another data item
		a0 = d.a0;
		a1 = d.a1;
		a = d.a;
	}
	
	void destroy(){
		a0 = a1 = a = 0;
	}
		
    void print(){	// pretty print
	
	}
		
    void set(const data & l, const data & r){ // parent from children
		a0 = l.a0 + r.a0;
		a1 = l.a1 + r.a1;
		a = max(l.a + r.a1, max(l.a0 + r.a1, l.a0 + r.a));
	}
		
	void combine_res(const data & l, const data & r){	//results
		set(l, r);
	}
	
	void upd(int op){ //update
    
	}
	
};
/*PROBLEM CODE ENDS HERE -- CHANGE THIS*/


/*GENERAL CODE STARTS HERE -- DO NOT CHANGE */
int MAX;
int SIZE;

class node{
	public:
	data d;
	
	int i, j;
	
	node(){
		i = j = -1;
    }
	
	
	void set(int i1){
		i = i1;
		j = i1;
		d.input(i1-1);
	}
	
	void set(const node & l, const node & r){		
               
                if (l.i == -1){
			i = r.i;
			j = r.j;
			d.copy(r.d);
		}
		else if(r.j == -1){
			i = l.i;
			j = l.j;
			d.copy(l.d);
		}
		else{
			i = l.i;
			j = r.j;
			d.set(l.d, r.d);
		}
	}
	
	void destroy(){
		i = j = -1;
		d.destroy();
	}
	
	
	
};

//node * A;
node A[SIZE_LIM];

void build_tree(int n){ //!IMP Index is 1-based, root node is 1
	MAX = 1;
	while (MAX < n) MAX <<= 1;
	SIZE = (MAX<<1);
	//A = new node[SIZE+1];
	for (int i = 0; i < n; i++){
		A[MAX+i].set(i+1);
            //if (DEBUG) A[MAX+i].print(MAX+i);
	}
	for (int i = MAX - 1; i > 0; i--){
		A[i].set(A[i<<1], A[(i<<1)+1]);
             //if (DEBUG) A[i].print(i);
        }
}


data query(int i, int j, int n = 1){			
    data nd;
    if (n > SIZE) return nd;
    if (i > j) return nd;
    if (i < 0 || j < 0) return nd;
    //if (DEBUG) cout<<"q : ("<<i<<", "<<j<<") at "<<n<<endl;
    int l = n<<1;
    int r = (n<<1) + 1;
    
    
    if (A[n].i == i && A[n].j == j){
        //if (DEBUG) cout<<"terminated!\n";
        return A[n].d;
    }
	if (A[l].i == -1 || i > min(j, A[l].j)){
		return query(max(i, A[r].i), j, r);
	}
	if (A[r].i == -1 || max(i, A[r].i) > j){
		return query(i, min(j, A[l].j), l);
	}
	nd.combine_res(query(i, min(j, A[l].j), l), query(max(i, A[r].i), j, r));
    return nd; //it ends here
}



int main(){
	int nt, n234;
	cin>>nt;
	while(nt--){
		int n;
		s(n);
		scanf("%s\n",str);
		fr(i, n+1) A[i].destroy();
		build_tree(n);
		int q;
		s(q);
		while(q--){
			int a, b;
			s(a);
			s(b);
			data d = query(a, b);
			printf("%d\n", max(d.a0, max(d.a1, d.a)));
		}
	}
	
	return 0;
}