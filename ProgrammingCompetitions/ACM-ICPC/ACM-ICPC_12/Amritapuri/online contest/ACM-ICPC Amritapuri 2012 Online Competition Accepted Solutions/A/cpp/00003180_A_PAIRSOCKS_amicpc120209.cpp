#include <stdio.h>
int main(){
    int t;
    scanf("%d",&t);
    int i,j;
    char a[51];
    int sr,sg,sw,sb;
    for(i=0;i<t;i++)
    {
       scanf("%s",a); 
       j=0;
       sr=0;
       sb=0;
       sw=0;
       sg=0;
       while(a[j]!='\0')  
       {
          if (a[j]=='R')
             sr++;
          if (a[j]=='G')
             sg++;       
          if (a[j]=='W')
             sw++;
          if (a[j]=='B')
             sb++;   
          j++;         
       }          
       if (sb%2==0 && sr%2==0 && sg%2==0 && sw%2==0)
          printf("YES\n");
       else
          printf("NO\n");
    }
    return 0;   
}
