//#include<cstidio>
#include<iostream>
#include<string>
using namespace std;


#define MAIN int main()
#define FOR(i,a,b) for(i=a; i<b; i++)

MAIN{
long int t, L[50000], n, m;
cin>>t;
long long a, b, c, ans;
long long dist, temp;
while(t--){
cin>>n>>m;
ans=0;
for(int i=0; i<n; i++){
cin>>L[i];
L[i]*=L[i];
}

cin>>a>>b>>c;
dist=a*a+b*b+c*c;
for(int i=1; i<m; i++){
cin>>a>>b>>c;
temp=a*a+b*b+c*c;
dist=temp>dist?temp:dist;
}
for(int i=0; i<n; i++){
if(L[i]<=dist)
ans++;
}
cout<<ans<<endl;
}

}
