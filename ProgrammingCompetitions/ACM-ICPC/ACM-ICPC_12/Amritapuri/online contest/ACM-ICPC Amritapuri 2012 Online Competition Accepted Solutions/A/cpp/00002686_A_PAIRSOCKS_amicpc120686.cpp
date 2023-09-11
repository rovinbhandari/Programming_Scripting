#include<cstdio>
#include<stdlib.h>
#include<iostream>
#include<fstream>
#include<stack>
#include<queue>
#include<string.h>

using namespace std;

ifstream fin("input.txt");
//#define cin fin

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        char A[100];
        scanf("%s",A);
        int B[10000];
        memset(B,0,sizeof(B));
        int len=strlen(A);
        for(int i=0;i<len;i++)
        {
            B[A[i]]++;
        }
        int ans=0;
        if(B['R']%2==1)
        ans=1;
        else
        if(B['G']%2==1)
        ans=1;
        else
        if(B['B']%2==1)
        ans=1;
        else
        if(B['W']%2==1)
        ans=1;
        if(ans==0)
        printf("YES\n");
        else
        printf("NO\n");
    }
    return 0;
}
