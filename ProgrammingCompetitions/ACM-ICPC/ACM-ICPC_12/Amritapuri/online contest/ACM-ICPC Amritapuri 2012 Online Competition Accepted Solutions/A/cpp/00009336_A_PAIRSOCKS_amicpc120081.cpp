#include<iostream>
#include<string>
using namespace std;
int main()
{
    
    int t;
    cin>>t;
        while(t--)
        {
                  string s;
                  cin>>s;
                  int x=s.length();
                  int i,r=0,w=0,b=0,g=0;
                  for(i=0;i<x;i++)
                  {
                                  char c=s[i];
                                  if(c==82)
                                  ++r;
                                  else if(c==71)
                                  ++g;
                                  else if(c==66)
                                  ++b;
                                  else if(c==87)
                                  ++w;
                  }
                  if( (r%2==0) && (g%2==0) && (b%2==0) && (w%2 ==0) )
                      cout<<"YES"<<endl;
                  else
        cout<<"NO"<<endl;
        }
}
