#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    int b[4],i,n,k,t;
    char a[55];
    scanf("%d",&t);
    while(t--)
    {
    memset(b,0,sizeof(b));
     scanf("%s",a);
    n=strlen(a);
    if(n%2==1)
    {
    printf("NO\n");
    continue;
    }
    for(i=0;i<n;i++)
    {
                    if(a[i]=='R')
                    b[0]++;
                    else if(a[i]=='G')
                    b[1]++;
                    else if(a[i]=='B')
                    b[2]++;
                    else if(a[i]=='W')
                    b[3]++;
    }
    k=0;
    for(i=0;i<4;i++)
    {
                    if(b[i]&1==1)
                    {
                    printf("NO\n");
                    k=1;
                    break;
                   }
    }
    if(k==0)
    printf("YES\n");
}
    return 0;
}
