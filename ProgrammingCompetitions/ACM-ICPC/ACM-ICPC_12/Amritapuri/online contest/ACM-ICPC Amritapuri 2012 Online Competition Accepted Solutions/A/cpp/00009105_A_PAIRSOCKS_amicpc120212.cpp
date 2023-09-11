#include <iostream>  
#include <cstring>  
#include <cstdlib>  
#include <cstdio>    
#define N 50

using namespace std;
int main()
{
int T;
cin>>T;
char *l[1000];
for(int i=1;i<=T;i++)
{
l[i]=(char *)malloc(N*sizeof(char));
scanf("%s",l[i]);
if((strlen(l[i]))>50)
{cout<<"String length should be atmost 50";
cin>>l[i];}}
int R,G,B,W;
char temp;
int m;
for(int i=1;i<=T;i++)
{ m=0;
  R=0;G=0;B=0;W=0;

  while(m<strlen(l[i]))
  {
  temp=l[i][m];
  if(temp=='R')
  R++;
  else if(temp=='G')
  G++;
  else if(temp=='B')
  B++;
  else if(temp=='W')
  W++;
  m++;
  }
  if(R%2==0 && G%2==0 && B%2==0 && W%2==0)
  cout<<"YES\n";
  else
  cout<<"NO\n";

}
return 0;
}