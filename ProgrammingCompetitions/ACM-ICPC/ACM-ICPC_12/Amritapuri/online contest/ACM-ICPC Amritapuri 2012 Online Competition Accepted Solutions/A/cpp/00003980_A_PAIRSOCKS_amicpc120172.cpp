#include<iostream>
#include<cstring>
using namespace std;

int main()
{
      int n,i,cases,r,b,g,wh;
      char w[100];
      cin>>cases;

      while(cases--)
      {
            r=0;b=0;g=0;wh=0;
            cin>>w;
            n=strlen(w);
            for(i=0;i<n;i++)
            {
                  if(w[i]=='R')
                        r++;
                  if(w[i]=='G')
                        g++;
                  if(w[i]=='W')
                        wh++;
                  if(w[i]=='B')
                        b++;
            }

            if((r%2==0)&&(b%2==0)&&(wh%2==0)&&(g%2==0))
                  cout<<"YES\n";
            else
                  cout<<"NO\n";
      }
      return 0;
}
