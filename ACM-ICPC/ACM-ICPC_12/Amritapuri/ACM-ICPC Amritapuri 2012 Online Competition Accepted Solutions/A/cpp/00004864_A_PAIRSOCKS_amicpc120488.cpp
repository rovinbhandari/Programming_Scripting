#include<iostream>
#include<string>
using namespace std;
int main()
{

int t;
cin>>t;
while(t--)
{ int r=0,g=0,b=0,w=0;
  string a;
  cin>>a;
  //len=a.length();
  int i=0;
  while(a[i]!='\0')
  { if(a[i]=='R')
    r++;
    else if(a[i]=='G')
          g++;
          else if(a[i]=='B')
               b++;
               else if(a[i]='W')
                    w++;
  i++;
  }
  if(r%2==0 && g%2==0 && b%2==0 && w%2==0)
  cout<<"YES\n";
  else
  cout<<"NO\n";
}
return 0;
}
