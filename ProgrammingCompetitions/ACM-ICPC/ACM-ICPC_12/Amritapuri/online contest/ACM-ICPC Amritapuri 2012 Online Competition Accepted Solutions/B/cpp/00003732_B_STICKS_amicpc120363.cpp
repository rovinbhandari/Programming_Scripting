#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;
int main()
{
    int t=0;
    cin>>t;
    while(t--)
    {
              long long s,b,c=0;
              cin>>s>>b;
              long long l[s];
              long long a[b][3];
              long long d[b],max=0;
              for(int i=0;i<s;i++)
                    {  cin>>l[i];
                       l[i]*=l[i];}
              for(int i=0;i<b;i++)
              {
                    cin>>a[i][0]>>a[i][1]>>a[i][2];
                    d[i]=(a[i][0]*a[i][0]+a[i][1]*a[i][1]+a[i][2]*a[i][2]);
                   // cout<<d[i];
                    if(max<d[i])
                    max=d[i];
              }
              for(int i=0;i<s;i++)
              if(l[i]<=max)
              c++;
              cout<<c<<endl;
    }
    //getch();
    return 0;
}
