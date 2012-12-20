#include<iostream>
#include<stdio.h>
using namespace std;
int main()
{
    int t;
    char ch[51];
    int r,b,g,w,i;
    scanf("%d",&t);
    while(t--)
    {
              r=0;
              w=0;
              b=0;
              g=0;
              scanf("%s",ch);
              for(i=0;ch[i]!='\0';i++)
              {
                                      if(ch[i]=='R')
                                      r++;
                                      else if(ch[i]=='G')
                                      g++;
                                      else if(ch[i]=='B')
                                      b++;
                                      else if(ch[i]=='W')
                                      w++;
                                      }
                                      if(r%2==0&&b%2==0&&g%2==0&&w%2==0)
                                      printf("YES\n");
                                      else
                                      printf("NO\n");
                                      }
                                      return 0;
                                      }
                                      
                                      
                                      
                                      
                                      
              
