#include <iostream>
#include <queue>
#include <vector>
#include <list>
using namespace std;

bool follow (list<int> *adlist, int i, int *C, int N) {
  queue<int> q;
  q.push(i);
  C[i]=0;
  while(!q.empty()) {
    int temp = q.front();
    list<int>::iterator it = adlist[temp].begin();
    int j;
    while ( it != adlist[temp].end() ){
      j = *it;
      if (C[j]== -1){
	q.push(j);
	C[j]=(C[temp]+1)%2;
      }
      else {
	if ( (C[j] != C[temp]) );
	else return false;
      }
      it++;
    }
    q.pop();
  }
  return true;
}
    


int main (){
  int T; cin >> T;
  //bool A[20000][20000];
  for (;T>0;T--){
    int N; cin >> N;   
    //for (int i=0; i<N; i++) for (int j=0; j<N; j++) A[i][j] = false;
    list<int> adlist[N];
     for (int i=0; i<N; i++) adlist[i] = list<int>();
    //vector<int> *R[N];
    for (int i=0; i<N; i++){
      int r; cin >> r;
      //R[i] = vector<int> (r);
      int temp;
      for (int j=0; j<r; j++) {
	cin >> temp;
	adlist[temp].push_back(i);
	adlist[i].push_back(temp);
	// A[i][temp] = A[temp][i] = true; 
      }
    }

    /* 
   list<int>::iterator it;
    for (int i=0 ; i<N; i++){
      it = adlist[i].begin();
      while (it != adlist[i].end()) {
	cerr << *it << " ";
	it++;
      }
      cerr << endl;
    }
    */

    int C[N];
    for (int i=0; i<N; i++) C[i]=-1;
    long long comps = 1;
    bool valid;
    for(int i=0; i<N; i++){
      if (C[i]==-1){
	valid = follow(adlist,i,C,N); 
	if (valid) comps=(comps*2)%1000000007;
	else {comps=0; break;}
      }
    }
    cout << comps << endl;
  }
  return 0;
}
