#include<cstdio>
#include<iostream>
#include<climits>
#include<cstdlib>
#include<algorithm>
#include<vector>
#include<map>

#define MAX 1000

using namespace std;

char str[MAX];

int main()
{

    int T;
    scanf("%d",&T);
    while(T--)
    {
        int N,Q;
        scanf("%s",str);
        //printf("%s\n",str);
        int r=0,g=0,b=0,w=0;
        for(int i=0;str[i];i++)
        {
            if(str[i]=='R')r++;
            if(str[i]=='G')g++;
            if(str[i]=='B')b++;
            if(str[i]=='W')w++;
        }
        if( ( (r&1)==0) && ((b&1)==0) && ((g&1)==0) && ((w&1)==0)  ) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}
