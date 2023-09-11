#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
int main()
{
 int t ,r, b, w, g;
 char c[50]={0};
 
 cin>>t;
 if(1<=t<=1000)
 {int i;
 for(i=1;i<=t;i++)
 {
r=0;
b=0;w=0;g=0;
  cin>>c;
  int j;
  for(j=0;c[j]!='\0';j++)
  {
   if((c[j]=='R')||(c[j]=='r'))
   r++;
   else if((c[j]=='W')||(c[j]=='w'))
   w++;
   else if((c[j]=='G')||(c[j]=='g'))
   g++;
   else if((c[j]=='B')||(c[j]=='b'))
   b++;
   
 
  }
  if((r%2==0)&&(g%2==0)&&(w%2==0)&&(b%2==0))
	cout<<"YES"<<endl;
  else
	cout<<"NO"<<endl;
 }
 

  
}

}
 


