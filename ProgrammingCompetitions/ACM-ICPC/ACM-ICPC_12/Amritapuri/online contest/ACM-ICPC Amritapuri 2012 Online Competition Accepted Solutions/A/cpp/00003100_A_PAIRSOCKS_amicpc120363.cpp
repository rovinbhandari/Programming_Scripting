#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    long long int t,i,countr,countg,countb,countw;
    cin>>t;
    while(t--)
    {
              char s[60];countr=0;countw=0;countb=0;countg=0;
              cin>>s;
              for(i=0;i<strlen(s);i++)
              {
                                      if(s[i]=='R')
                                      countr++;
                                      else if(s[i]=='G')
                                      countg++;
                                      else if(s[i]=='B')
                                      countb++;
                                      else if(s[i]=='W')
                                      countw++;
                                      }
                                      if(countr%2==0 && countg%2==0 && countb%2==0 && countw%2==0)
                                      cout<<"YES"<<endl;
                                      else
                                      cout<<"NO"<<endl;
                                      }
                                      //getch();
                                      return 0;
                                      }
                                      
