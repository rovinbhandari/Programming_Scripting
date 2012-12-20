#include<iostream>
#include<cstring>
using namespace std;

int main()
{
   int t,i,a[4];
   string s;
    cin>>t;
    while(t--)
     {
        cin>>s;
          int l=s.length();
        for(i=0;i<4;i++)
           a[i]=0;
        for(i=0;i<l;i++)
         {
              if(s[i]=='R')
                    a[0]++;

               else if(s[i]=='G')
                    a[1]++;

                 else if(s[i]=='B')
                    a[2]++;

                 else if(s[i]=='W')
                    a[3]++;
           }
 
        if(a[0]%2==0&&a[1]%2==0&&a[2]%2==0&&a[3]%2==0)
             cout<<"YES"<<"\n";
         else
             cout<<"NO\n";
    }
  return 0;
}
