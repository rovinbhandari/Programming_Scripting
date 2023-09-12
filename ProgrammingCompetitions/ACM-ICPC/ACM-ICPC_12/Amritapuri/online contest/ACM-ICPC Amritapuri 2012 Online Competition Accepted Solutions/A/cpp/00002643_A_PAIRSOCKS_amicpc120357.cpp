/* 
 * File:   main.cpp
 * Author: SCORPIUS
 *
 * Created on November 4, 2012, 7:57 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    int t;
    cin>>t;
    while(t--){
        int r=0,g=0,b=0,w=0;
        string s;
        cin>>s;
        for(int i=0;i<s.length();i++){
            r+=(s[i]=='R');
            g+=(s[i]=='G');
            b+=(s[i]=='B');
            w+=(s[i]=='W');
        }
        if(!(r&1 || g&1 || b&1 ||w&1)) cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
                
    }

    return 0;
}

