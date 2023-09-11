#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int t;
    scanf("%d",&t);
    while(t--){
               int n,m;
               scanf("%d%d",&n,&m);
               vector <long long int> vec;
               for(int i=0;i<n;++i){
                       long long int l;
                       scanf("%lld",&l);
                       vec.push_back(l);
                       }
               long long int ml=0;
               for(int j=0;j<m;++j){
                       long long int a,b,c;
                       scanf("%lld%lld%lld",&a,&b,&c);
                       long long int s=a*a+b*b+c*c;
                       if(ml<s)
                               ml=s;
                       }
               int c=0;
               for(int i=0;i<vec.size();++i){
                       if(vec[i]*vec[i]<=ml)
                                     c++;
                       }
               printf("%d\n",c);
               }
    return 0;
}
