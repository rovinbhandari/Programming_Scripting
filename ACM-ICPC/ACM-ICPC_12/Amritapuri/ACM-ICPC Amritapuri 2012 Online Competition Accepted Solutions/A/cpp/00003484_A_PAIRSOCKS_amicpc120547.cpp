#include<iostream>
#include<stack>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    int i,t;
    string s;
    cin>>t;
    while(t--)
    {
              cin>>s;
              stack<char>red,green,blue,white;
              for(i=0;i<s.length();i++)
              {
                                       if(s[i]=='R')
                                       {
                                                    if(!red.empty())
                                                    {
                                                                    red.pop();
                                                    }
                                                    else red.push('R');
                                       }
                                       else if(s[i]=='G')
                                       {
                                                    if(!green.empty())
                                                    {
                                                                    green.pop();
                                                    }
                                                    else green.push('G');
                                       }
                                       else if(s[i]=='B')
                                       {
                                                    if(!blue.empty())
                                                    {
                                                                    blue.pop();
                                                    }
                                                    else blue.push('B');
                                       }
                                       else if(s[i]=='W')
                                       {
                                                    if(!white.empty())
                                                    {
                                                                    white.pop();
                                                    }
                                                    else white.push('W');
                                       }
              }
              if(blue.empty() && red.empty() && green.empty() && white.empty())
                              cout<<"YES"<<endl;
              else cout<<"NO"<<endl;
    }
}

                                       
              
