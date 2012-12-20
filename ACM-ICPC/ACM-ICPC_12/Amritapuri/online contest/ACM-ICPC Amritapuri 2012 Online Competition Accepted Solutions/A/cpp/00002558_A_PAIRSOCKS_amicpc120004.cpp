
#include <iostream>
#include <string>
using namespace std;
int main()
{

    int r,g,b,w,t,i;
    cin>>t;
    string str;
    while(t--)
     {
         cin>>str;
         int n = str.size();
         r=g=b=w=0;
         for(i=0;i<n;i++)
          {
              if(str[i]=='R')
                r++;
              else if(str[i]=='W')
                w++;
              else if(str[i]=='G')
                g++;
              else b++;
          }
         if(r%2==0 && w%2==0 && g%2==0 && b%2==0)
           cout<<"YES";
        else cout<<"NO";
        cout<<endl;
     }
}
