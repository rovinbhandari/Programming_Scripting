#include <iostream>
using namespace std;

int main(){

int n;
cin>>n;
string s;


for(int i=0;i<n;i++)
{
   int c[4]={0};
   cin>>s;
   if(s.length()%2!=0)
   {
  	cout<<"NO\n";
    continue;
    }
    for(int j=0;j<s.length();j++)
    {
        
        if(s[j]=='R')
        c[0]++;
    	
    	if(s[j]=='B')
        c[1]++;
        
        if(s[j]=='W')
        c[2]++;
        
        if(s[j]=='G')
        c[3]++;
    }
   
   if(c[0]%2==0&&c[1]%2==0&&c[2]%2==0&&c[3]%2==0)
   cout<<"YES\n";
   else
   cout<<"NO\n";
 }




}
