#include<iostream>
#include<cmath>
using namespace std;

int main()
{
      long long n,i,j,cases,m,cnt,l,b,h;
      long long a,d,max=0;
      int len[100000]={0};
      cin>>cases;

      while(cases--)
      {
            max=-1;cnt=0;
            cin>>n>>m;
            for(i=1;i<=n;i++)
                  cin>>len[i];
            for(j=1;j<=m;j++)
            {
                  cin>>l>>b>>h;
                  a=(l*l)+(b*b)+(h*h);
                  d=sqrt(a);
                  //cout<<"d="<<d<<endl;
                  if(max<d)
                        max=d;
            }

            for(i=1;i<=n;i++)
            {
                  if(len[i]<=max)
                        cnt++;
            }
            cout<<cnt<<endl;
      }
      return 0;
}
