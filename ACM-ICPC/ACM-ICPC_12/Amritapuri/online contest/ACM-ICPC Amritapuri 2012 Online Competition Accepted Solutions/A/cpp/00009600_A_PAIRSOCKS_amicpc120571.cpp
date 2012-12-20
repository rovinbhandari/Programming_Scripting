#include<cstdio>
#include<iostream>
#include<string>
using namespace std;
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
     string s;
     cin>>s;
     int r=0,g=0,w=0,b=0,i=0;
     i=s.length();
    // printf("i=%d\n",i);
     while(i--)
     {
     //printf("%c\n",s.at(i));
      if(s.at(i)=='R')                 
        r=r^1           ;
      else if(s.at(i)=='G')
       g=g^1;
      else if(s.at(i)=='W')
       w=w^1;
      else
       b=b^1;
     }     
     //printf("%d %d %d %d\n",r,g,w,b);   
     if(r+w+g+b==0)
      printf("YES\n");
     else
      printf("NO\n");
     } 
return 0    ;
}
