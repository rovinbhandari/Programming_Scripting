#include<iostream>
#include<string.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
      char ch[51];
      cin>>ch;
      int len=strlen(ch),i;
      int r=0,g=0,b=0,w=0,ct=0;
      for(i=0;i<len;i++)
      {
        if(ch[i]=='R')
        r++;
        else if(ch[i]=='G')
        g++;
        else if(ch[i]=='B')
        b++;
        else if(ch[i]=='W')
        w++;
      }
      if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
      ct=1;
      if(ct==1)
      cout<<"YES\n";
      else 
      cout<<"NO\n";
    }
    //system("pause");
    return 0;
}
      
      
