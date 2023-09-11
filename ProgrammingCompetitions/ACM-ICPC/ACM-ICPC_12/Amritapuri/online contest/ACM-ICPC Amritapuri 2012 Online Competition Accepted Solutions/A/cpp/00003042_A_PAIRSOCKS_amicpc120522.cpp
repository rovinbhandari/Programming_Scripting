/*
    Nimesh Ghelani (nims11)
*/
#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
#include<cmath>
#include<stack>
#include<utility>
#define in_T int t;for(scanf("%d",&t);t--;)
#define in_I(a) scanf("%d",&a)
#define in_F(a) scanf("%lf",&a)
#define in_L(a) scanf("%lld",&a)
#define in_S(a) scanf("%s",a)
#define newline printf("\n")
#define MAX(a,b) a>b?a:b
#define MIN(a,b) a<b?a:b
#define SWAP(a,b) {int tmp=a;a=b;b=tmp;}
#define P_I(a) printf("%d",a)

using namespace std;
int main()
{
    in_T
    {
        string str;
        cin>>str;
        int r=0,g=0,b=0,w=0;
        for(int i=0;i<str.length();i++)
        {
            switch(str[i])
            {
                case 'R':
                r++;
                break;
                case 'G':
                g++;
                break;
                case 'B':
                b++;
                break;
                case 'W':
                w++;
                break;
            }
        }
        if(r%2 || g%2 || b%2 || w%2)
            cout<<"NO\n";
            else
            cout<<"YES\n";
    }
}
