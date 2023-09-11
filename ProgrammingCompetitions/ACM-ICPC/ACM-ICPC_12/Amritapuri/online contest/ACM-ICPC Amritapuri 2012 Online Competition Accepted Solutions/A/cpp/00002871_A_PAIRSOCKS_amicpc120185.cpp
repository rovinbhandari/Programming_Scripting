#include<cstdio>
#include<iostream>
using namespace std;
int main()
{
    string s;
    int i,j,t;
    scanf("%d",&t);
    while(t--)
    {
        int a[4]={0};
        cin>>s;
        for(i=0;i<s.length();i++)
        {
            if(s[i]=='R')
                a[0]++;
            else if(s[i]=='B')
                a[1]++;
            else if(s[i]=='W')
                a[2]++;
            else if(s[i]=='G')
                a[3]++;
        }
        if(a[0]%2==0 && a[1]%2==0 && a[2]%2==0 && a[3]%2==0)
            printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
