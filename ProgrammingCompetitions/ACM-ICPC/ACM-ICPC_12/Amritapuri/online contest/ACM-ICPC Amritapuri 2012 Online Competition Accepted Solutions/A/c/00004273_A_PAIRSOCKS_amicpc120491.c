#include<stdio.h>
//#include<conio.h>
#include<string.h>
int main()
{
    char a[50];
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
         int rc=0,rg=0,rb=0,rw=0;
         scanf("%s",a);
         for(i=0;i<strlen(a);i++)
         {
               switch(a[i])
               {
                           case 'R':
                                rc++;
                                break;
                                
                           case 'G':
                                rg++;
                                break;
                           case 'B':
                                rb++;
                                break;
                           case 'W':
                                rw++;
                                break;
               }
         }
         if((!(rc%2))&&(!(rg%2))&&(!(rb%2))&&(!(rw%2)))
         printf("YES\n");
         else
         printf("NO\n");
    }
    //getch();
    return 0;
}
