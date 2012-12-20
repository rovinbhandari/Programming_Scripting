#include<iostream>
#include<string>
using namespace std;
 
int main()
{
    int T;
    string A;
     int r,g,b,w,c,f=0;
     cin>>T;
while(T-->0)
{
    cin>>A;
 r=0,g=0,b=0,w=0,c=0;
for(int i=0;i<A.length();i++)
{
 
 if(A[i]=='R')
 r++;
 //cout<<r<<endl;
 if(A[i]=='G')
 g++;
 //cout<<g<<endl;
 if(A[i]=='B')
 b++;
 //cout<<b<<endl;
 if(A[i]=='W')
 w++;
 //cout<<w<<endl;
}
 
 if(r%2!=0)c++;
 
 if(b%2!=0)c++;

 if(g%2!=0)c++;

 if(w%2!=0)c++;

 
 if(c==0)
 cout<<"YES"<<endl;
 else
 cout<<"NO"<<endl;
}
return 0;
}