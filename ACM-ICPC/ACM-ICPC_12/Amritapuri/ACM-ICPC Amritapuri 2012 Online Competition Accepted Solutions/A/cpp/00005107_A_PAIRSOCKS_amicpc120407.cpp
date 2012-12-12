#include<iostream>
#include<stdio.h>
#include<string.h>
//#include<conio.h>
#include<map>
using namespace std;


int main()
{
 int t,z;
 scanf("%d",&t);
 z=t;
 map<char,int> dummy;
 getchar();
 while(z--)
           {    int flag=0;
                char s[51];
                
                dummy['R']=0;
                dummy['G']=0;
                dummy['B']=0;
                dummy['W']=0;
                
                char c;
                gets(s);
                int q=0;
                
                while(s[q]!='\0')
                                          {//cout<<q;
                                           dummy[s[q]]++;
                                           //cout<<dummy[s[q]];
                                           q++;
                                          }
                if(!dummy['R'] && !dummy['G'] && !dummy['B'] && !dummy['W'])
                               {cout<<"NO\n";
                                continue;}
                if((dummy['R']%2==0)&&(dummy['G']%2==0)&&(dummy['B']%2==0)&&(dummy['W']%2==0))
                                                                      {
                                                                      cout<<"YES\n";
                                                                      continue;
                                                                      }
                else
                {cout<<"NO\n" ;
                continue      ;
                }
                
                
                
           }
 //getch();
 return 0;
}
