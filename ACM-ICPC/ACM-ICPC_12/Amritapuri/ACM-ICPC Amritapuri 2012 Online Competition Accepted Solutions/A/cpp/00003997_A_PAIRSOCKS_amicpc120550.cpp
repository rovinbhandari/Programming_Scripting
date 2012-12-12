
#include<stdio.h>
#include<string.h>
#define MAX_LENGTH 50
int main()
{
    char c,string[MAX_LENGTH];
    unsigned int test_case,i,length,count_R , count_G ,count_W,count_B;
    scanf("%d",&test_case);
    for(i = 0 ; i < test_case; i++)
    {
          count_R = 0;
          count_G = 0;
          count_B = 0;
          count_W = 0;
          scanf("%s",string);
          length = strlen(string);
          while(length >0)
          {
                    //   strcpy(c,string[length-1]);
                      c = string[length-1];
                       if(c == 'R')
                       {
                            count_R++;
                       }
                       else  if(c == 'G')
                       {
                            count_G++;
                       }
                       else if(c == 'B')
                       {
                            count_B++;
                       }
                       else if(c == 'W')
                       {
                            count_W++;
                       }
          length--;
          }
          if(count_R%2 == 0 && count_G%2 == 0 && count_B%2 == 0 && count_W%2 == 0)
          {
                       printf("YES\n");
                       }
                       else
                       {
                           printf("NO\n");
                           }
    }
    return 0;
    }
