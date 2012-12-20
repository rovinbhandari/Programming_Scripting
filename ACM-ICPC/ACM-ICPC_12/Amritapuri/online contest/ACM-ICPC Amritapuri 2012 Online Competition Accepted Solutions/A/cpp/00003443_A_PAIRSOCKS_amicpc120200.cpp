#include<iostream>
#include<string.h>
#include<cctype>
#define  LU int 
using namespace std;
int main()
{
    int t;
    cin>>t;
    string a;
    while(t--)
    {
      LU b[4]={0};
      cin>>a;
      for(int i=0;i<a.size();i++)
      {
       if(a.at(i)=='R')
        b[0]++;
        else if(a.at(i)=='W')
        b[1]++;
        else if(a.at(i)=='G')
        b[2]++;
        else
        b[3]++;
      }
      if(b[0]%2==0&&b[1]%2==0&&b[2]%2==0&&b[3]%2==0)
      cout<<"YES\n";
      else
      cout<<"NO\n";
      }      
    
    return 0;
    
    
    
}
