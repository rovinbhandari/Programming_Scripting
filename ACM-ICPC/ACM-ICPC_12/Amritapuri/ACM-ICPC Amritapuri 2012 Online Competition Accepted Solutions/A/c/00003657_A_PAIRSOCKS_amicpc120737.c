#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <math.h>
#define ModNum 1000000007
extern int getchar_unlocked(void);
extern int putchar_unlocked(int c);
int inpint();
long long inplong();
inline int inpint()
{
int noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
}
inline long long inplong()
{
long long noRead=0;
char p=getchar_unlocked();
for(;p<33;){p=getchar_unlocked();};
while(p>32)
{
noRead = (noRead << 3) + (noRead << 1) + (p - '0');
p=getchar_unlocked();
}
return noRead;
}
int main()
{
 int T;
 for(T=inpint();T>0;T--)
     {
      int countR=0,countW=0,countB=0,countG=0;
      char c=0;
      while((c=getchar_unlocked())!='\n')
       { 
         switch(c)
           {
             case 'R':countR++;break;
             case 'B':countB++;break;
             case 'G':countG++;break;
             case 'W':countW++;break;     
             } 
       }
      if(!((countR&1)|(countB&1)|(countG&1)|(countW&1)))  
         printf("YES\n");
      else printf("NO\n");  
      }
return 0;
}
