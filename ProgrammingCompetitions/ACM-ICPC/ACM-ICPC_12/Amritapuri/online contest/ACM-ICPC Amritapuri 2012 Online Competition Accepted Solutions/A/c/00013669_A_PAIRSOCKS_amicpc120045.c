#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  int arr[4]={0,0,0,0},t,i,x;
  char c[51],v;
  scanf("%d",&t);
  while(t--)
  {
		arr[0]=0;
		arr[1]=0;
		arr[2]=0;
		arr[3]=0;
            scanf("%s",c);
            x=strlen(c);
            
            for(i=0;i<x;i++)
            {
                   switch(c[i])
                   {
                               case 'R':
                                    arr[0]++;
                                    break;
                               case 'G':
                                    arr[1]++;
                                    break;
                               case 'B':
                                    arr[2]++;
                                    break;
                               case 'W':
                                    arr[3]++;
                                    break;
                   }
                   
            }
            if(arr[0]&1 || arr[1]&1 || arr[2]&1 || arr[3]&1)
                               printf("NO\n");
                   else
                          printf("YES\n");
  }
 // system("PAUSE");	
  return 0;
}
