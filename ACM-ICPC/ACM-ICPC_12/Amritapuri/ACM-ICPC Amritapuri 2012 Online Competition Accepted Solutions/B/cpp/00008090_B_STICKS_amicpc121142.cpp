//includes
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <queue>
#include <list>
#include <stack>
#include <map>
#include <set>
#include<cstring>
#include<math.h>
using namespace std;




//datatypes
#define I unsigned long long int
#define C unsigned char
#define VI std::vector<int> 
#define VC std::vector<char>
#define max3(a,b,c) a>b?(a>c?a:c):(b>c?b:c);
#define max2(a,b) a>b?a:b;

//loops
#define PT(n) int n;cin>>n;while(n--)
#define FOR(n) for(int i=0;i<n;i++)
#define FORI(A) for(std::vector<int>::iterator it=A.begin();it!=A.end();it++)

//functions
#define sort(a) std::sort(a.begin(),a.end())
#define PB push_back
#define SZ size()

#define _ <<

//sting utils
#define SPLIT(str,A)					\
  char * cstr, *p;					\
  cstr = new char [str.size()+1];			\
  strcpy (cstr, str.c_str());				\
  p=strtok (cstr," ");					\
  while (p!=NULL){					\
    A.push_back(p);					\
    p=strtok(NULL," ");					\
  }							\
							\
  delete[] cstr;					\
 
  
/*GLOBALS*/
std::vector<string> S;
std::vector<string>::iterator st;



//main
int main(){
  VI L;

  std::vector< std::vector<unsigned long long int> > B;
  
  PT(T){

    I M,N;

    cin>>N>>M;
    
    while(N--){
      int n;
      cin>>n;

      L.PB(n);

    }

    while(M--){
      unsigned long long int arr[3];
      cin>>arr[0]>>arr[1]>>arr[2];
      std::vector<unsigned long long int> a;
      a.PB(arr[0]);
      a.PB(arr[1]);
      a.PB(arr[2]);

      B.PB(a);
      
    }



    I bsize=B.size();
    I max=0;
  
    //cout<<"size:"<<B.size();
    for( int i=0; i< bsize;i++){
      
      unsigned long long int sum=0;
      for(int j=0;j< 3;j++){

	sum+=  B[i][j]*B[i][j];
      }

      
      max= max2( sqrt(sum),max);
      //cout<<"kl:"<<pro<<endl;
      
    }
    //cout<<"max: "<<max<<endl;

    int c=0;
    FORI(L){

      if( *it <=max )
	c++;
    }
    
    cout<< c<<endl;
    L.clear();
    B.clear();
  }

  
}
  
  
