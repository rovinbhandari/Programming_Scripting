#include<iostream>
//#include<conio.h>
#include<string.h>
using namespace std;
int main()
{  int cases,white,blue,green,red,i,len;
string str;
    cin>>cases;
    while(cases--)
    {  red=green=blue=white=0;
                  cin>>str;
                  len=str.size();
                  if(len==1) {cout<<"NO\n";continue;}
                  for(i=0;i<len;i++)
                  {
                    if(str[i]=='R') red++;
                    if(str[i]=='G') green++;
                    if(str[i]=='B') blue++;
                    if(str[i]=='W') white++;
                  }
    if(red%2==0&&green%2==0&&blue%2==0&&white%2==0)
    {cout<<"YES\n";}
    else cout<<"NO\n";
}
//getch();
return 0;
}
