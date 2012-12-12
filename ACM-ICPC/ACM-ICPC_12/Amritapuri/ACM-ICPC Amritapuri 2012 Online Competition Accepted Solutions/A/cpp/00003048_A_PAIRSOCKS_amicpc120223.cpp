#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;



int main(){
    int t;
    cin>>t;
    char s[10000];
    while(t--)
    {
        int a[200]={0};
        scanf("%s",s);
        for(int i=0;i<strlen(s);i++)
        {
            a[s[i]]++;
        }

        int flag=1;
        if(a['R']%2)
        flag=0;
        if(a['G']%2)
        flag=0;
        if(a['B']%2)
        flag=0;
        if(a['W']%2)
        flag=0;

        if(flag==1)
        cout<<"YES\n";
        else
        cout<<"NO\n";

    }

    return 0;
}


