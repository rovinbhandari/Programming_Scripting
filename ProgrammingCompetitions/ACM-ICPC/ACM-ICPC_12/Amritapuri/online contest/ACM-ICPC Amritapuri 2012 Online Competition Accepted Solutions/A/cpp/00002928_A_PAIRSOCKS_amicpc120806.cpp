#include<iostream>
#include<map>
#include<vector>
#include<string>
using namespace std;
int main()
{
    long int t,i,j,k;
    map<char,int>m;
    map<char,int> :: iterator it;
    string s;
    cin>>t;
    while(t--)
    {
              long int flag=1;
              m.clear();
              cin>>s;
              for(i=0;i<s.length();i++)
                        m[s[i]]++;               
              for(it=m.begin();it!=m.end();it++)
              {
                                                if((*it).second%2!=0)
                                                {
                                                                     flag=0;
                                                                     break;
                                                }
              }
              if(flag)
                      cout<<"YES\n";
              else
                  cout<<"NO\n";
    }
    return 0;
}
