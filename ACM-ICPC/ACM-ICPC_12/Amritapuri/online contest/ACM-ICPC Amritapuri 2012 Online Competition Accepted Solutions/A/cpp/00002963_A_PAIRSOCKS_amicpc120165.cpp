#include<iostream>
#include <math.h>
#include<string.h>
using namespace std;
int main(){
int a,b;
cin>>a;
char s[1002];
while(a--){
    cin>>s;
    int xx[200]={0};
    for(int i=0;s[i]!='\0';i++){
        xx[s[i]]++;

    }
    if(xx['R']%2==0&&xx['G']%2==0&&xx['B']%2==0&&xx['W']%2==0)
    cout<<"YES\n";
    else
    cout<<"NO\n";
}
}
