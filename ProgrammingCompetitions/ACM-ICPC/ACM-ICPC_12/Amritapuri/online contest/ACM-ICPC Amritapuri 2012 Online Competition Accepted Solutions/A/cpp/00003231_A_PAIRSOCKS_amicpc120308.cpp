#include<cstdio>
int main()
{
    int a[4],t,i;
    char str[50];
    scanf("%d",&t);
    while(t--)
    {
   a[0]=0;
   a[1]=0;
   a[2]=0;
   a[3]=0;
     scanf("%s",str);
     for(i=0;str[i]!='\0';i++)
     {
                              if(str[i]=='R')
                                             a[0]++;
                              else if(str[i]=='G')
                                             a[1]++;
                              else if(str[i]=='B')
                                             a[2]++;
                              else
                                             a[3]++;
     }
     if(a[0]%2==0 && a[1]%2==0 && a[2]%2==0 && a[3]%2==0) 
                  printf("YES\n");
     else
                  printf("NO\n");                                                 
               
    }
    return 0;
}
