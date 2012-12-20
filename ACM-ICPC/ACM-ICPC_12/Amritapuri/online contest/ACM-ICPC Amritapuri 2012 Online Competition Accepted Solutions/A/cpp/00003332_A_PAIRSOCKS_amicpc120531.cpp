#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
using namespace std;

int main()
{
    int t,r,g,b,w;
    char str[55];
    scanf("%d",&t);
    while(t--)
    {
     r=g=b=w=0;         
     scanf("%s",str);
     int i;
     i=0;        
     int len;
     len=strlen(str);
     for(i=0;i<len;i++)
     {
      if(str[i]=='R')
       r++;
      else if(str[i]=='G')
       g++;
      else if(str[i]=='W')
       w++;
      else if(str[i]=='B')
       b++;                  
     }
     if(r%2==0 && b%2==0 && g%2==0 && w%2==0)
      printf("YES\n");
     else
      printf("NO\n");  
    }   
 return 0;   
}
