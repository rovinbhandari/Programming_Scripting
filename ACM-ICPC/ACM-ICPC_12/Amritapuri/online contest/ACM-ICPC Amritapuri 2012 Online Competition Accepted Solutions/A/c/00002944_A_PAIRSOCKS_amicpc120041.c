#include<stdio.h>
int main()
{
    int n[4],i,t;
    char a[1001];
    scanf("%d",&t);
    while(t--)
    {
     scanf("%s",a);
     n[0]=n[1]=n[2]=n[3]=0;
     for(i=0;i<strlen(a);i++){
     if(a[i]=='R')
     n[0]++;
     if(a[i]=='G')
     n[1]++;
     if(a[i]=='B')
     n[2]++;
     if(a[i]=='W')
     n[3]++;
     }
     if(n[0]%2==0&&n[1]%2==0&&n[2]%2==0&&n[3]%2==0)
     printf("YES\n");
     else
     printf("NO\n");
    }
   // scanf("%d");
    return 0;
    
}
