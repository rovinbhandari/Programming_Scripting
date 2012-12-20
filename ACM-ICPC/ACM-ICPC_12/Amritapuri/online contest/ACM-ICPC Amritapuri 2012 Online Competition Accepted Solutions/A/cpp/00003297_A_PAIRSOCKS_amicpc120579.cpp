#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
    char c[55];
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
              int a[4]={0};
       scanf("%s",&c);
       n=strlen(c);
                       for(i=0;i<n;i++)
                       {
                                       if(c[i]=='R')
                                       a[0]++;
                                       if(c[i]=='G')
                                       a[1]++;
                                       if(c[i]=='B')
                                       a[02]++;
                                       if(c[i]=='W')
                                       a[3]++;
                       }
                       if(a[0]%2==0&&a[1]%2==0&&a[2]%2==0&&a[3]%2==0)
                       printf("YES\n");
                       else
                       printf("NO\n");
}
                                       return 0;
}
