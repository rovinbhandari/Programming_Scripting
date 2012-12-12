#include<iostream>
using namespace std;
int main()
{
 int r=0, g=0, b=0, w=0;
 string a;
 int i, flag=0, n;
 
 cin>>n;
 while(n--)
 {
  r=0,g=0,b=0,w=0; 
  flag = 0;
  cin>>a;
  for(i=0;i<(int)a.length();i++)
  {
   if(a[i] == 'R')
    r++;
   else if (a[i] == 'G')
    g++;
   else if(a[i] == 'B')
    b++;
   else if(a[i] == 'W')
    w++;
  }
 
  if(r%2 == 0)
   if(b%2 == 0)
    if(g%2 == 0)
     if(w%2 == 0)
      flag = 1;

  if(flag == 1)
   cout<<"YES";
  else
   cout<<"NO";
  cout<<endl;
 }
 return 0;
}
