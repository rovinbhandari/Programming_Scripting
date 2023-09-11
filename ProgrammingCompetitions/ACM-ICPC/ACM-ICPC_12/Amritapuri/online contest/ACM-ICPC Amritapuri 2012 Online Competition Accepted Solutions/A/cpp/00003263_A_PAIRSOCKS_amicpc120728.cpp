#include<iostream>
#include<string.h>
#include<vector>
#include<cctype>
#include<cstdio>
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
int main()
{
int t;
scanf("%d",&t);
char arr[100];
while(t--)
{
int r=0,g=0,b=0,w=0;
scanf("%s",&arr);
for(int i=0;i<strlen(arr);++i)
{
if(arr[i]=='R')
r++;
else if(arr[i]=='G')
g++;
else if(arr[i]=='B')
b++;
else if(arr[i]=='W')
w++;


}
if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
printf("YES\n");
else
printf("NO\n");
}
return 0;
}
