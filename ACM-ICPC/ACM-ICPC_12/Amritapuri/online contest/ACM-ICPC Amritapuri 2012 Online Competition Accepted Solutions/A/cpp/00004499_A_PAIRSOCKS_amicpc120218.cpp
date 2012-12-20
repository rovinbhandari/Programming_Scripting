#include<iostream>
#include<map>
#include<string>

using namespace std;

int main(){
    long long int t,i;
    cin>>t;
    string s;
    
    while(t--){
    map<char,long long int> a;
        cin>>s;
        for(i=0;i<s.size();i++){
            a[s[i]]++;
        }
        if(a['R']%2!=0 || a['G']%2!=0 || a['B']%2!=0 || a['W']%2!=0 || (a['R']==0 && a['G']==0 && a['B']==0 && a['W']==0))
            cout<<"NO"<<endl;
        else
            cout<<"YES"<<endl;
    }
    return 0;
}
