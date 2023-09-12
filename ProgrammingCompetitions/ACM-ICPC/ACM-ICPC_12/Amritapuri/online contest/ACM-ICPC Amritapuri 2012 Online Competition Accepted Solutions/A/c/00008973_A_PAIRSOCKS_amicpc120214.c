#include<stdlib.h>
#include <stdio.h>
#include<string.h>

enum {RED,BLUE,GREEN,WHITE};
int socks[4];

int main()
{
  int tc,i,k,flag;
  char str[50];
  scanf("%d",&tc);
  for( k = 0; k < tc; k++)
  {
    flag=0;
    scanf("%s",str);
    for(  i = 0;i<strlen(str); i++ ){
        if( str[i] == 'R' )
          socks[RED]++;
        else if( str[i] == 'G' )
          socks[GREEN]++;
         else if( str[i] == 'W' )
           socks[WHITE]++;
         else if( str[i] == 'B' )
            socks[BLUE]++;
   }
   for(  i=0; i<4 ; i++){
         if(socks[i] % 2 != 0){
            printf("NO");
            flag=1;        
            break;
         }
         }
         if(flag == 0)         
              printf("YES");
    for(  i=0; i<4 ; i++)
      socks[i] = 0;
    printf("\n");
   }
   return 0;
   }
