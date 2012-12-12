#include<stdio.h>
#include<string.h>
int main()
{
    int i,tc,p,a[4],ans[1000];
    char str[50];
    scanf("%d",&tc);
    p=tc;
    while(tc)
    {
    a[0]=0;
    a[1]=0;
    a[2]=0;
    a[3]=0;
     scanf("%s",str);
	i=0;
     while(str[i]!='\0')
     { 
	if(str[i]=='R')
        {a[0]++;}
       if(str[i]=='G')
        {a[1]++;}
       if(str[i]=='W')
       {a[2]++;}
       if(str[i]=='B')
       {a[3]++;}
       i++;
     }
     if(a[0]%2==0 && a[1]%2==0 && a[2]%2==0 && a[3]%2==0)
     {
        ans[tc]=1;
     }
     else
     {
         ans[tc]=0;
     }
     tc--;
    }
    while(p)
    {
            if(ans[p]==1)
     {
        printf("YES\n");
     }
     else
     {
         printf("NO\n");
     }
     p--;
     }
return 0;
}
