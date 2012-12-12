/** author -- Ayush Sharma **/
#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cstdlib>
#include<cassert>
#include<algorithm>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define min3(a,b,c) (a<b?(a<c?a:c):(b<c?b:c))
#define max3(a,b,c) (a>b?(a>c?a:c):(b>c?b:c))
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define MAX 100001
#define infi 100000
using namespace std;
typedef long long LL;
int main(){
    int test;
    scanf("%d",&test);
    while(test--){
        char str[100];
        cin>>str;
        int len=strlen(str);
        int r=0,g=0,b=0,w=0;
        FOR(i,0,len){
            if(str[i]=='R')r++;
            else if(str[i]=='G')g++;
            else if(str[i]=='B')b++;
            else if(str[i]=='W')w++;
        }
        if(r%2!=0 || g%2!=0 ||b%2!=0 || w%2!=0 )printf("NO\n");
        else {printf("YES\n");}
    }
    return 0;
}
