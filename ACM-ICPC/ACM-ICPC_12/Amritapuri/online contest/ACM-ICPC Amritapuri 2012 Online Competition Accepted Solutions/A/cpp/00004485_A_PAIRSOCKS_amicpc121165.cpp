#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int main()
{
    int t,red,green,blue,white;
    scanf("%d",&t);
    if(t<1 || t>1000)
       return 0;
    char c[50];
   for(int j=0;j<t;j++)
    {
       scanf("%s",c);
       int n=strlen(c);
       red=blue=green=white=0;
       for(int i=0;i<n;i++)
        {
            if(c[i]=='R' || c[i]=='G' || c[i]=='B' || c[i]=='W')
            {
               if(c[i]=='R')
                  red++;
               else if(c[i]=='G')
                 green++;
               else if(c[i]=='B')
                   blue++;
               else if(c[i]=='W')
                  white++;
            }
            else 
               return 0;
        }
       if((red%2==0) && (green%2==0) && (blue%2==0) && (white%2==0))
          printf("YES\n");
       else
         printf("NO\n");
    }
    return 0;
}
