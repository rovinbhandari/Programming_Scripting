#include <iostream>
#include <string.h>
using namespace std;
int pair1(char a[]);
int main() {
int i,T=0;
int yesorno[1000];
char c[50];
cin>>T;
for(i=0;i<T;i++)
{
    cin>>c;
    yesorno[i]=pair1(c);
}
for(i=0;i<T;i++)
{
    if(yesorno[i]==1)
    cout<<"YES"<<endl;
    else if(yesorno[i]==0)
    cout<<"NO"<<endl;
}
    
}

int pair1(char a[])
{
int r=0;
int g=0;
int b=0;
int w=0;
int i=0;
  for(i=0;i<strlen(a);i++)
  {
      switch(a[i])
      {
          case 'R':r++;
                    break;
          case 'G':g++;
                    break;
          case 'B':b++;
                    break;      
          case 'W':w++;
                    break;
      
      }
  }
      if(((r%2)==0)&&((g%2)==0)&&((b%2)==0)&&((w%2)==0))
      {return 1;}
      else
      return 0;
      
}
  
