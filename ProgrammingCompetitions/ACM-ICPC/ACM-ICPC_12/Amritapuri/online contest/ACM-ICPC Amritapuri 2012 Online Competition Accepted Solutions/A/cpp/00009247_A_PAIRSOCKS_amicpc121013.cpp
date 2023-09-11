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
 int r=0;
 int g=0;
 int b=0 ;
 int w=0;
 char a[50];
 gets(a);
 for(int j=0;j<strlen(a);j++)
  { 
 
 if(a[j]=='R')
   {
   r++;
   }
  else if(a[j]=='G')
   {
   g++;
   }
   else if(a[j]=='B')
   {
   b++;
   }
   else if(a[j]=='W')
   {
   w++;
   }
}
 if ((r%2==0) && (b%2==0) && (g%2==0) && (w%2==0))
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
