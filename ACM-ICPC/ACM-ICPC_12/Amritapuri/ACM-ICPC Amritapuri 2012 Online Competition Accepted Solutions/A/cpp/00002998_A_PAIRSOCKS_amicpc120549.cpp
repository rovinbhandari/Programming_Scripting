//team:voidpointers
#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#define max(a,b) (a>b)?a:b
#define min(a,b) (a<b)?a:b
#define f(n) for(int i=0;i<n;i++)
using namespace std;
typedef long long ll;
int main(){
    int t,n,r,g,b,w;
    char a[51];
    scanf("%d",&t);
    while(t--){
        scanf("%s",&a);
        n = strlen(a);
        r=0;b=0;g=0;w=0;
        f(n){
        if(a[i]=='R')r++;
        else if(a[i]=='G')g++;
        else if(a[i]=='B')b++;
        else w++;
        }
        if(!(r%2) && !(b%2) && !(g%2) && !(w%2))
        printf("YES\n");
        else
        printf("NO\n");
    }
return 0;
}
