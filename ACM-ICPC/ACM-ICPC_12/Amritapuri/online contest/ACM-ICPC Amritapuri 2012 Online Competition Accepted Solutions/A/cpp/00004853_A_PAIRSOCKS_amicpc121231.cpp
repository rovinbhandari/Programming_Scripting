#include<iostream>
using namespace std;
#include<string.h>
int main()
{
     char c[1000][51];
     int i,j,l,rc=0,gc=0,bc=0,wc=0,t,rf=0,gf=0,wf=0,bf=0;
     cin>>t;
     for(i=0;i<t;i++)
          cin>>c[i];
     for(i=0;i<t;i++)
     {
               l=strlen(c[i]);
               rc=0;
               gc=0;
               wc=0;
               bc=0;
               for(j=0;j<l;j++)
                 {
                                 switch(c[i][j])      
                                 {
                                          case 'R':rc++;
                                                   break;
                                          case 'W':wc++;
                                                   break;
                                          case 'G':gc++;
                                                   break;
                                          case 'B':bc++;
                                                   break;
                                     }
                 }
                 if(rc%2==0&&bc%2==0&&gc%2==0&&wc%2==0)     
                         cout<<"YES\n";
                 else
                         cout<<"NO\n";
     }
     return 0;
}
     
                                          
       
       
