#include <stdio.h>
#include <string.h>

int main()
{
    int T,i,j,len;
    int test=4;
    char RGBW[4];
    char socks[50];
    scanf("%d", &T);
    for(i=1;i<=T;i++)
    {
                       memset(RGBW, 0, 4);
                       scanf("%s",&socks);
                       len=strlen(socks);
                       for(j=0;j<len;j++)
                       {
                                            if(socks[j]=='R' || socks[j]=='r')
                                            {
                                                             RGBW[0]++;
                                                             }
                                            else if(socks[j]=='G' || socks[j]=='g')
                                            {
                                                 RGBW[1]++;
                                                 }
                                            else if(socks[j]=='B' || socks[j]=='b')
                                            {
                                                 RGBW[2]++;
                                                 }
                                            else if(socks[j]=='W' || socks[j]=='w')
                                            {
                                                 RGBW[3]++;
                                                 }
                                                 }
                       if(RGBW[0]==0 && RGBW[1]==0 && RGBW[2]==0 && RGBW[3]==0)
                       {
                                     printf("NO\n");
                                     continue;
                                     }                                     
                       if(RGBW[0]%2==0 && RGBW[1]%2==0 && RGBW[2]%2==0 && RGBW[3]%2==0)
                       {
                                       printf("YES\n");
                                       continue;
                                       }
                       else
                       {
                                       printf("NO\n");
                                       }
                                       }
                                       return 0;
                                       }
                       
