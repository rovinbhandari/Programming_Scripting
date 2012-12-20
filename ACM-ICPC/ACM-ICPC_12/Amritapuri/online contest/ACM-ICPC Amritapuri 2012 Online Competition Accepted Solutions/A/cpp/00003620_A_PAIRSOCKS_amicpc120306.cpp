#include<iostream>
#include<stdio.h>
#include<cstring>
using namespace std;
int main()
{
    int i ,len, t, pairs[4];
    char sock[51];
    bool flag;
    scanf("%d",&t);
    while(t--)
    {
        flag= true;
        memset(pairs,0,sizeof(pairs));
        scanf("%s",sock);
        len = strlen(sock);
        for(i=0;i<len;i++)
        {
            if(sock[i]=='R')
            {
                pairs[0]++;
            }
            else  if(sock[i]=='G')
            {
               pairs[1]++;
            }
            else        if(sock[i]=='B')
            {
                             pairs[2]++;
            }
            else           if(sock[i]=='W')
            {
                                           pairs[3]++;
            }
        }
        for(i=0;i<4;i++)
        {
                        if(pairs[i]&1)
                        {
                                      printf("NO\n");
                                      flag= false;
                                      break;
                        }
        }
        if(flag)
        printf("YES\n");
        }
        return 0;
    }
        
        
