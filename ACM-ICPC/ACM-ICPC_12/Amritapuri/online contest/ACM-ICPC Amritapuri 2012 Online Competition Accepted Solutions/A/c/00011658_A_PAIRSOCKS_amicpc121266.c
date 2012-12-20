#include<stdio.h>
#include<string.h>
 
int main()
{
   int i=0,j,T,r,g,b,w;
   char s[50];
   scanf("%d\n",&T);
   for(j=0;j<T;j++)
    {
       r =0;g=0;b=0;w=0;
           scanf("%s",s);
           //printf("%s",s);
           if(strlen(s) > 50 ) {printf("Length Exceeded\n"); return -1;}
		   i=0;
           while( s[i] != '\0')
            {
             if(s[i] == 'R')
               r++;
             if(s[i] == 'G')
               g++;
             if(s[i] == 'W')
               w++;
             if(s[i] == 'B')
               b++;                        
                  if(s[i] != 'R' && s[i] != 'G' && s[i] != 'B' && s[i] != 'W' )
            {
                          printf("Wrong Chars entered\n"); return -1;}
                
                  i++;
            }
if(((r%2) == 0) && ((g%2) == 0) && ((b%2) == 0) && ((w%2) == 0))    
          printf("YES\n");
        else
      printf("NO\n");           
        
    
}
  return 0;
}