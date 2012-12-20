#include<iostream>
#include<math.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--)
    {
              int n,m,count=0;
              cin>>n>>m;
              double a[n],l1,l2,l3,max,dim;
              for(int i=0;i<n;i++)
              cin>>a[i];
              cin>>l1>>l2>>l3;
              max=sqrt(l1*l1+l2*l2+l3*l3);
              for(int i=1;i<m;i++)
              {
                      cin>>l1>>l2>>l3;
                      dim=sqrt(l1*l1+l2*l2+l3*l3);
                      if(max<dim)
                      max=dim;
              }
              for(int i=0;i<n;i++)
              {
                      if(a[i]<=max)
                      count++;
              }
              cout<<count<<endl;
    }
    return 0;
}
