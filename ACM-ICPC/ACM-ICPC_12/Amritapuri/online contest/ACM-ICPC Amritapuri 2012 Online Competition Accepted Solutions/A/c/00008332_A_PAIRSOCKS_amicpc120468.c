#include<stdio.h>
#include<string.h>

int main()
{
    int t=0;
    scanf("%d", &t);
    while(t--)
    {
              char c='A',str[51]={'\0'};
              int a[5],i,k=0;
              for(i=0;i<5;i++)
                              a[i]=0;
              scanf("%s", &str);
              if(strlen(str)==1)
                               printf("NO\n");
              else
              {
              while(k<strlen(str))
              {
              
                          c=str[k];
                       
                              switch(c)
                              {
                                       case 'R':a[0]++;
                                            break;
                                       case 'G':a[1]++;
                                            break;
                                       case 'B':a[2]++;
                                            break;
                                       case 'W':a[3]++;
                                            break;
                              }
                              k++;
                         
              }
              int flag=0;
              for(i=0;i<4;i++)
              {
                              if(a[i]%2!=0)
                                           flag=1;
              }
              if(flag==0)
                         printf("YES\n");
              else
                         printf("NO\n");
              }
    }
  
    return 0;
}
              
