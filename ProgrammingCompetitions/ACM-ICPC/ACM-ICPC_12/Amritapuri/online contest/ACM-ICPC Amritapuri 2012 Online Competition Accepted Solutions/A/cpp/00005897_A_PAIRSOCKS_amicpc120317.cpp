#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

int main()

{    ios::sync_with_stdio(false);
    char inp[100];
    int count[4],T,i;
    cin>>T;
    for(int j=0;j<T;j++)
    { count[0]=0;
      count[1]=0;
      count[2]=0;
      count[3]=0;
      cin>>inp;
      i=0;
      while(inp[i]!='\0')
      {
                     if(inp[i]=='R')
                     count[0]++;
                     else if(inp[i]=='G')
                     count[1]++;
                     else if(inp[i]=='B')
                     count[2]++;
                     else if(inp[i]=='W')
                     count[3]++;
                     i++;
      }
      if(count[0]%2==0&&count[1]%2==0&&count[2]%2==0&&count[3]%2==0)
       cout<<"YES\n";
      else cout<<"NO\n";
    }   
  return(0);
}
