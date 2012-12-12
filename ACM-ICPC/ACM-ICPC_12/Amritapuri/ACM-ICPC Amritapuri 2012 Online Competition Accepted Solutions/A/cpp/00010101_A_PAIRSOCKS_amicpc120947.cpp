#include <iostream>
#include <vector>
#include <map>
#include <string>
#define N 100000
using namespace std;

typedef long long LL;
int main()
{
int t;  map<char,int> sock; string s;
cin>>t;
while(t--)
{
	string s;
	sock['R']=0;sock['B']=0;sock['G']=0;sock['W']=0;
	cin>>s;
	int i1=0;int n=s.length();
	while(i1<n){sock[s[i1]]++;i1++;}
	if(sock['R']%2==0 && sock['B']%2==0 && sock['G']%2==0 && sock['W']%2==0)cout<<"YES\n";
	else cout<<"NO\n";
}
return 0;
}
