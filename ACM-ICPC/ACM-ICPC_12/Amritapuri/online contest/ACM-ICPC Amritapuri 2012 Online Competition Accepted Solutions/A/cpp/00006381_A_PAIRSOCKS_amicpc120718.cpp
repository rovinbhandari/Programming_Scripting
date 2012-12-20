#include<iostream>
#include<string>

using namespace std;

class tcase{
      string s;
      int flag;
      
      public:
             void get()
             {
                  int r=0,g=0,b=0,w=0;
                  cin>>s;
                  for(int i=0;s[i]!='\0';i++)
                  {                          
                          if(s[i]=='R')
                                       r++;
                          if(s[i]=='G')
                                       g++;
                          if(s[i]=='B')
                                       b++;
                          if(s[i]=='W')
                                       w++;
                          }
                  if(r%2==0&&g%2==0&&b%2==0&&w%2==0)
                                                    flag=1;
                  else
                      flag=0;
                  } 
                  
             void put()
             {
                  if(flag==1)
                             cout<<"YES"<<endl;
                  else
                      cout<<"NO"<<endl;
                  }  
      };
main()
{
      int testcase;
      cin>>testcase;
      tcase t[testcase];
      for(int i=0;i<testcase;i++)
      {
              t[i].get();      
      }
      for(int i=0;i<testcase;i++)
      {
              t[i].put();      
      }

}
