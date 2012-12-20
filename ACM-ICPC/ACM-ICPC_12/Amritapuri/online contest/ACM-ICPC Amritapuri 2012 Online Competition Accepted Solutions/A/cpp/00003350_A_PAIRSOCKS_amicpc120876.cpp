#include<stdio.h>

int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       char st[100];
       int i,a=0,b=0,c=0,d=0;
       scanf("%s",&st);
       for(i=0;st[i]!='\0';i++)
       {    
        if(st[i]=='R'){a++;}
        else if(st[i]=='G'){b++;}
        else if(st[i]=='B'){c++;}
        else d++;
      }    
      
        if(!(a%2)&&!(b%2)&&!(c%2)&&!(d%2))
          {printf("YES\n");}
          else
          {printf("NO\n");}
    }
    
    
    
return 0;    
}
