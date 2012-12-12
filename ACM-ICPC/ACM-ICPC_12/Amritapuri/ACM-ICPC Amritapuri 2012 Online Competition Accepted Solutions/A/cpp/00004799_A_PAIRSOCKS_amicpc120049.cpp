#include<iostream>
#include<string>

using namespace std;

int main()
{
    char a[70];
    int t,j;
    cin>>t;
    for(j=0;j<t;j++){
    cin>>a;
    int i=0,r=0,b=0,g=0,w=0;
    while(a[i]!='\0')
    
    {
                     if(a[i]=='R')
    r++;
        if(a[i]=='B')
    b++;             
     if(a[i]=='G')
    g++;
     if(a[i]=='W')
    w++;
                    i++;
                     }
    if(g%2==0&&r%2==0&&b%2==0&&w%2==0)
    cout<<"YES\n";
    else cout<<"NO\n";
}

    
}
