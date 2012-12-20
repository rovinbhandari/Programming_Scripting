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

map<char,int> cnt;
int main(){
//    'R'gbw
    int t,i;
    string s;
    cin>>t;
    while(t--){
               cnt.clear();
               cin>>s;
               for(i=0;i<s.length();i++)
                cnt[s[i]]++;
               if(cnt['R']%2==0&&cnt['G']%2==0&&cnt['B']%2==0&&cnt['W']%2==0)
                 cout<<"YES"<<endl;
               else cout<<"NO"<<endl;
    }
    
    return 0;
}
