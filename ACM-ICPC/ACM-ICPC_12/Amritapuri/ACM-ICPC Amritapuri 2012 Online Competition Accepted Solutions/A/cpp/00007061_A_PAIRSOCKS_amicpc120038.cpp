#include<stdio.h>
#include<string.h>
//using namespace std;
int main()
{
int t,len,j,i,r,g,b,w; char str[100];
scanf("%d",&t);
for( j=0;j<t;j++)
{ r=g=b=w=0;
          scanf("%s",str);
          int len=strlen(str);
          for(i=0;i<len;i++)
          {
                            if(str[i]=='R' )
                            {
                                  r++;         
                                           }
                                            if(str[i]=='G' )
                            {
                                  g++;         
                                           }
                                            if(str[i]=='W' )
                            {
                                  w++;         
                                           }
                                            if(str[i]=='B' )
                            {
                                  b++;         
                                           }
                          
                            }
        if(r%2==0 && g%2==0 && w%2==0 && b%2==0 )
        printf("YES\n");
        else 
        printf("NO\n");
          }
return 0;
}
