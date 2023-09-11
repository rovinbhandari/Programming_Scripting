#include<iostream>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        string s;
        int i,flag;
        cin>>s;
        int a[4]={0,0,0,0};
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='R')
              a[0]++;
            else if(s[i]=='G')
              a[1]++;
            else if(s[i]=='B')
              a[2]++;
            else a[3]++;
        }
        flag=0;
        for(i=0;i<4;i++)
        {
            if(a[i]%2==0);
            else flag=1;
        }
        if(flag) cout<<"NO\n";
        else cout<<"YES\n";
    }
    return 0;
}
