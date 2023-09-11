
#include<iostream>
#include<cstdlib>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<string>
#include<cctype>
#include<sstream>
#include<cmath>
#include<list>
#include<stack>
#include<map>
#include<bitset>
#include<set>
#include<cstring>
using namespace std;
typedef long long ll;
int main()
{
    ll i,j,k,n,m,t;int arr[4];
    cin>>t;
    while(t--)
    {
      arr[0]=arr[1]=arr[2]=arr[3]=0;
      string s;
      cin>>s;
      for(i=0;i<s.length();i++){if(s[i]=='R')arr[0]++;if(s[i]=='B')arr[1]++;if(s[i]=='G')arr[2]++;if(s[i]=='W')arr[3]++;}
      //cout<<arr[0]<<endl<<arr[1]<<endl<<arr[2]<<endl<<arr[3]<<endl;
      if(arr[0]%2==0 && arr[1]%2==0 && arr[2]%2==0 && arr[3]%2==0)cout<<"YES"<<endl;else cout<<"NO"<<endl;
    }
}
