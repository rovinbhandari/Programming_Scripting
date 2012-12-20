# include<iostream>
# include<cstdio>
# include<cstring>
using namespace std;
int main()
{
    string s;
    int t,i,l,r,g,b,y;
    while(cin>>t)
    {
                 while(t--)
                 {
                 //getchar();
                 cin>>s;
                 r=0;
                 b=0;
                 g=0;
                 y=0;
                 for(i=0;i<s.length();++i)
                 {
                     if(s[i]=='R')
                     ++r;
                     else if(s[i]=='G')
                     ++g;
                     else if(s[i]=='W')
                     ++y;
                     else
                     ++b;
                 }
                 if((r%2==0)&&(y%2==0)&&(g%2==0)&&(b%2==0))                     
                 cout<<"YES\n";
                 else
                 cout<<"NO\n";
                 }
    }
    return 0;
}
