#include <cstdlib>
#include <iostream>

using namespace std;
int main()
{
    int n,t,r=0,g=0,w=0,b=0;
    
    cin>>t;
    int *p= new int [t];
    char a[50];
    for(int j=0;j<t;j++)
    {
            r=0;b=0;g=0;w=0;
            cin>>a;
            
            for(int i=0;a[i];i++)
            {
            if(a[i]=='R')
            r++;
            else if(a[i]=='G')
            g++;
            else if(a[i]=='W')
            w++;
            else if(a[i]=='B')
            b++;
            }
if(r%2==0)
{
          if(b%2==0)
          
                    if(g%2==0)
                    
                              if(w%2==0)
                              
                                        *(p+j)=1;
                                        }
}

for(int i=0;i<t;i++)
if(*(p+i)==1)
cout<<"YES"<<"\n";
else
cout<<"NO"<<"\n";


    
    
    return 0;
    
}
