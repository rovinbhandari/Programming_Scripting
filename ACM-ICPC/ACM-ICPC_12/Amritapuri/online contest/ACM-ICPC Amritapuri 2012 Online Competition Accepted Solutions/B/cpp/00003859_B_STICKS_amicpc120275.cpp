 #include<iostream>
#include<queue>
#include<map>
#include<cstdio>
#include<cmath>
#include<sstream>
#include<algorithm>
#include<vector>
#include<cstdlib>
#include<cstring>
#include<stdio.h>
#include<string.h>

using namespace std;

int main(){
    int t;
    long long n,m,i;
    vector<double> stick;
    double a,b,c;
    cin>>t;
    double temp;
    double x;
    while(t--){
               x=0.0;
               stick.clear();
               cin>>n>>m;
               for(i=0;i<n;i++){
                cin>>temp;
                stick.push_back(temp);
               }
               for(i=0;i<m;i++)
               {
                  cin>>a>>b>>c;
                  x=max(x,sqrt( a*a+b*b+c*c));
               }
               //cout<<x<<endl;
               int cnt=0;
               for(i=0;i<n;i++){
                     if(stick[i]<=x)
                       cnt++;                              
               }
               cout<<cnt<<endl;    
    }
    
    return 0;
}
