#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
#include<queue>
#include<string>
#include<map>
#include<cstring>
#include<cctype>
using namespace std;

int main()
{
    char str[51];
    int T;
    int i;
    for(scanf("%d",&T);T--;)
    {
        scanf("%s",str);
        sort(str,str+strlen(str));
        i=0;
        while(str[i] != '\0' && str[i] == 'B') i++;
        if(!(i & 1)) while(str[i] != '\0' && str[i] == 'G') i++;
        else { cout<<"NO\n"; continue; }
        if(!(i & 1)) while(str[i] != '\0' && str[i] == 'R') i++;
        else { cout<<"NO\n"; continue; }
        if(!(i & 1)) while(str[i] != '\0' && str[i] == 'W') i++;
        if((i & 1)) { cout<<"NO\n"; continue; }
        cout<<"YES\n";
    }
}
