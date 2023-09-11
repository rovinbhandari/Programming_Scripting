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

  
  PT(T){

    std::string s;
    
    cin>>s;
    
    int r=0,b=0,g=0,w=0;
    FOR(s.size()){

      if( s[i]=='R')
	r++;
      if( s[i]=='G')
	g++;
      if(s[i]=='B')
	b++;
      if(s[i]=='W')
	w++;
    }
    
    //    cout<<w<<" "<<r<<" " <<g<< " "<<b<<endl;
    if( (r%2==0) && (g%2==0) && (b%2==0) && (w%2==0) )
      cout<<"YES"<<endl;
    else
      cout<<"NO"<<endl;
    


  }

  
}
  
  
