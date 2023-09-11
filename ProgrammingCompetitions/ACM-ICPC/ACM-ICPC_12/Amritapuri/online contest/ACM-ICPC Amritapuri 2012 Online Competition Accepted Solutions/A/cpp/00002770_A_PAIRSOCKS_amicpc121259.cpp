#include<cstdio>
#include<iostream>

using namespace std;

int main(){

  long long int t;
  long long int r=0,g=0,b=0,w=0;
  string s;

  cin>>t;
  
  while(t--){
    r=g=b=w=0;
    cin>>s;
    
    long long int n = s.size();

    for(long long int i=0;i<n;i++){
      if(s[i] =='R')r++;
      if(s[i] =='B')b++;
      if(s[i] =='G')g++;
      if(s[i] =='W')w++;
    }
    
    if(r%2 ==0 && b%2 ==0 && g%2 ==0 && w%2 ==0){
      cout<<"YES"<<endl;
    }
    else{
      cout<<"NO"<<endl;
    }
  }

  return 0;
}
