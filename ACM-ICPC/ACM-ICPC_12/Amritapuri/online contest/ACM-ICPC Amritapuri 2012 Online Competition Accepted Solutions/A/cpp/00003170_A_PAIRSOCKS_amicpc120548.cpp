#include<iostream>
#include<vector>
#include <string>
using namespace std;
int main()
{
    
    string a;
    int n;
    cin>>n;
while(n--)
{cin>>a;
    int i;
    vector<int>b(4,0);
    for(i=0;a[i];i++)
    {
                     if(a[i]=='B')
                     {
                                  b[0]++;
                     }
                     else
                         if(a[i]=='G')
                         {
                                      b[1]++;
                         }
                         else
                         if(a[i]=='W')
                         {
                                      
                                      b[2]++;
                         }
                         else
                         {
                             b[3]++;
                         }
                     
    }
    
    for(i=0;i<4;i++)
    b[i]=b[i]%2;
     if(b[0]||b[1]||b[2]||b[3])
     {
                               cout<<"NO\n";
     }
     else
     cout<<"YES\n";
     }
}
