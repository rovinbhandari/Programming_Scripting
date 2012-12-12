#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int main()
{
       long long int n,t,i,j,c=0,m,a,b,c1;
       cin>>t;
       while(t--)
       {c=0;
       cin>>n>>m;
      long long int s[n];
       for(i=0;i<n;i++)
       cin>>s[i];
       long long int  mi,md=0;
       for(i=0;i<m;i++)
       {
              cin>>a>>b>>c1;
              //sort(a,a+3);
              mi=sqrt(a*a+b*b+c1*c1);
              md=max(md,mi);
              //k++;
       }
       for(j=0;j<n;j++)
       {if(s[j]<=md)
       c++;

       }
       cout<<c<<endl;
       }return 0;
}
