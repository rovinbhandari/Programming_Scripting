/* r -0
g - 1
b - 2
w - 3
*/
#include<stdio.h>
#include<string.h>
#define N 50
int main()
{
 int T,i,j,r,g,b,w;
 char c[50];
 char result[1000][4];
 scanf("%d",&T);
 for(i=0;i<T;i++)
 {
  scanf("%s",c);
  r=g=b=w=0;
  for(j=0;j<strlen(c);j++)
  {
   switch(c[j])
   {
    case 'R':r++;
    	     break;
    case 'G':g++;
    	     break;
    case 'B':b++;
             break;
    case 'W':w++;
             break;
   }
  }
   if(r%2 || g%2 || b%2 || w%2)
      strcpy(result[i],"NO");
   else
      strcpy(result[i],"YES");
 }
 for(i=0;i<T;i++)
  printf("%s\n",result[i]);
 return 0;
}
 
