#include<iostream>
#include<cstring>
using namespace std;
int main()
{
int n;
cin>>n;

for(int i=0;i<n;i++)
{
    int r=0,g=0,w=0,b=0;
char s[55];
    cin>>s;
    for(int j=0;j<strlen(s);j++)
    {
        if(s[j]=='R') r++;
        else if(s[j]=='G') g++;
        else if(s[j]=='B') b++;
        else w++;
     }
     if(r%2==0 && g%2==0 && w%2==0 && b%2==0) 
     cout<<"YES"<<endl;
     else cout<<"NO"<<endl;
}
return 0;
}

