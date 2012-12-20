#include<iostream>
#include<math.h>
#include<map>
using namespace std;

int main()
{
    long long t;
    map<int,long long> stick;
    cin>>t;
    while(t--)
    {
         	stick.clear();
              long long n,m;
              char y;
              long long l,b,h;
              long long diag,maxi=0;
              cin>>n>>m;
              for(long long i=0;i<n;i++)
                              cin>>stick[i];

		//cout<<n<<" "<<m<<" ";
              for(long long i=0;i<m;i++)
              {
                      cin>>l>>b>>h;
                      diag=long(sqrt(l*l+b*b+h*h));
                      if(diag>maxi)
                                  maxi=diag;
              }
              long long ctr=0;
//cout<<maxi<<" ";
              for(long long i=0;i<n;i++)
              {
                              if(stick[i]<=maxi)
                                               ctr++;
              }
              cout<<ctr<<endl;
              /*if(t!=0)
              {
            
                      cin>>y;
              }*/
                      
    }
    return 0;
}
