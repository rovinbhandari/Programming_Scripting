#include<iostream>
#include<string>
#include<cstring>
#include<cstdio>
using namespace std;
int main()
{
    int T,r,g,b,w,i;
    string str;
    char ch;
    cin>>T;
    ch=getchar();
    while(T--){
               r=0; g=0; b=0; w=0;
               getline(cin,str);
               for(i=0;i<str.length();i++){
                                           if(str[i]=='R') r++;
                                           if(str[i]=='G') g++;
                                           if(str[i]=='B') b++;
                                           if(str[i]=='W') w++;
                                           }
               if(r%2==0 && g%2==0 && b%2==0 && w%2==0) cout<<"YES\n";
               else cout<<"NO\n";
               }
    return 0;
}
               
