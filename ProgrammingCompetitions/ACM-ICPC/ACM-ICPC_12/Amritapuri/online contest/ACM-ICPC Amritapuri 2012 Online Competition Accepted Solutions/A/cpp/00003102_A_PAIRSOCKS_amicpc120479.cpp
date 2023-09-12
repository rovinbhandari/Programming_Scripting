#include<iostream>
#include<string>
using namespace std;
int main()
{ 
    int t;cin>>t;
    while(t--)
    {
    string s;bool r=0,b=0,w=0,g=0;
    cin>>s;
    for(int i=0;i<s.length();i++)
    {
            if(s[i]=='R') r=!r; 
            if(s[i]=='B') b=!b;
            if(s[i]=='W') w=!w;
            if(s[i]=='G') g=!g;
            }
    if(r==0 && b==0 && w==0 && g==0)cout<<"YES"<<endl;
    else cout<<"NO"<<endl;        
    }
    return 0;
}
