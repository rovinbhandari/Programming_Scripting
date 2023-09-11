#include<iostream>
#include<string>
using namespace std;

int main()
{
    int t, i, len, cnt[5], done;
    string str;
    
    cin>>t;
    
    while(t--)
    {
              cin>>str;
              len = str.size();
              done=1;
              
              for(i=0;i<5;i++)
              cnt[i]=0;
              
              for(i=0;i<len;++i)
              {
                  if(str[i]=='R')
                  { cnt[0]++; }
                  else if(str[i]=='G')
                  { cnt[1]++; }
                  else if(str[i]=='B')
                  { cnt[2]++; }
                  else if(str[i]=='W')
                  { cnt[3]++; }
              }
              
              
              for(i=0;i<4;i++)
              {
                              //cout<<cnt[i]<<'\n';
                  if(cnt[i]%2)
                  { //cout<<i<<" "<<cnt[i]<<'\n'; 
                  done=0; break; }
              }
              
              if(done==1)
              cout<<"YES\n";
              else
              cout<<"NO\n";
    }
    
    return 0;
}
