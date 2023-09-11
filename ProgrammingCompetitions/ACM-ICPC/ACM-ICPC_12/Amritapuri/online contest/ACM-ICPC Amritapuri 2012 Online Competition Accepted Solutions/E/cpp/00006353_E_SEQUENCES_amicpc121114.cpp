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



class data{
	public:
	int a0, a1, a;
	// declare variables
     
    data(){	// initialize
		a0 = a1 = a = 0;
	}
	
    void input(){ // input from STDIN
		char i1;
		cin>>i1;
		int i = i1 - '0';
		a0 = (i == 0);
		a1 = (i == 1);
		a = 0;
	}
		
	void copy(const data & d){	// copy another data item
		a0 = d.a0;
		a1 = d.a1;
		a = d.a;
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
	
	int flag[10], nflags;			
	int i, j;
	
	node(){
		i = j = -1;
        nflags = NFLAGS;                  
		fr(k, nflags) flag[k] = 0;
	}
	
	void print(int ind = 0){
                if (i == -1) return;
		cout<<ind<<" : ("<<i<<", "<<j<<") ";
		d.print();
		fr(k, nflags) cout<<flag[k];
                cout<<endl;
	}
	
	void set(int i1){
		i = i1;
		j = i1;
		d.input();
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
	
	void set_flag(int k){
		flag[k] = (flag[k]+1)%2;
	}
	
	void unset_flag(int k){
		flag[k] = (flag[k]+1)%2;
		d.upd(k);
	}
	
};

node * A;

void build_tree(int n){ //!IMP Index is 1-based, root node is 1
	MAX = 1;
	while (MAX < n) MAX <<= 1;
	SIZE = (MAX<<1);
	A = new node[SIZE+1];
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
    
    for (int k = 0; k < A[n].nflags; k++){       
        while(A[n].flag[k]){
            A[n].unset_flag(k);
            if (l < SIZE) A[l].set_flag(k);
            if (r < SIZE) A[r].set_flag(k);
        }
    }
    
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
    return nd;
}


void modify(int i, int j, int op, int n = 1){ 
    if (n > SIZE) return;
	if (i < 0 || j < 0) return;
    
    int l = n<<1;
    int r = (n<<1) + 1;
    	
    for (int k = 0; k < A[n].nflags; k++){
        while(A[n].flag[k]){
            A[n].unset_flag(k);
            if (l < SIZE) A[l].set_flag(k);
            if (r < SIZE) A[r].set_flag(k);
        }
    }
    
    if (i > j) return;
    if (i > A[n].j || j < A[n].i) return;
    //if (DEBUG) cout<<"m : ("<<i<<", "<<j<<") at "<<n<<" op "<<op<<endl;
    
    
    if (A[n].i == i && A[n].j == j){	
        //if (DEBUG) cout<<"terminated!\n";
        if (l < SIZE) A[l].set_flag(op);
        if (r < SIZE) A[r].set_flag(op);
        return A[n].d.upd(op);
    }
	modify(i, min(j, A[l].j), op, l);
	modify(max(i, A[r].i), j, op, r);
    
    return A[n].set(A[l],A[r]);
}

void print_tree(int i = 1){
    if (A[i].i == -1) return;
    int l = i<<1;
    int r = (i<<1) + 1;
    if (l < SIZE) print_tree(l);
    int i1 = 2;
    while(i1 <= i){
        cout<<"\t";
        i1 <<= 1;
    }
    A[i].print(i);
    if (r < SIZE) print_tree(r);
}


int main(){
	int nt;
	cin>>nt;
	while(nt--){
		int n;
		cin>>n;
		build_tree(n);
		int q;
		s(q);
		while(q--){
			int a, b;
			s(a);
			s(b);
			data d = query(a, b);
			cout<<max(d.a0, max(d.a1, d.a))<<endl;
		}
	}
	
	return 0;
}