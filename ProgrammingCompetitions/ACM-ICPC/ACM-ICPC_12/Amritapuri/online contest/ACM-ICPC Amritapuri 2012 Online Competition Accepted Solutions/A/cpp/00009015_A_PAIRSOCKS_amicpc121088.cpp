#include<iostream>
#include<stdio.h>
#include<string.h>

using namespace std;

int main()
{
int t,i=0;
cin>>t;
getchar();
while (i<t)
 {
 int cr=0;
 int cg=0;
 int cb=0 ;
 int cw=0;
 char c[50];
 gets(c);
 for(int j=0;j<strlen(c);j++)
  { 
 
 if(c[j]=='R')
   {
   cr++;
   }
  else if(c[j]=='G')
   {
   cg++;
   }
   else if(c[j]=='B')
   {
   cb++;
   }
   else if(c[j]=='W')
   {
   cw++;
   }
}
 if ((cr%2==0) && (cb%2==0) && (cg%2==0) && (cw%2==0))
  {
  cout<<"YES"<<endl;
  }
else
{
  cout<<"NO"<<endl;
 }
i++;


}
return 0;
}
