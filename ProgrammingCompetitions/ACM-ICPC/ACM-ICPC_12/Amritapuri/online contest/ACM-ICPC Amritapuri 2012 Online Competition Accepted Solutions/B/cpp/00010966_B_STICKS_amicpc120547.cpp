#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
int main()
{
    int t;
    long long int m,n,i,x,a,b,c;
    scanf("%d",&t);
    while(t--)
    {
              cin>>n>>m;
              vector<long long int>stick;
              long long int ctr=0,temp,len=0;
              for(i=0;i<n;i++)
              {
                              cin>>x;
                              stick.push_back(x);
              }
              for(i=0;i<m;i++)
              {
                              cin>>a>>b>>c;
                              temp=a*a+b*b+c*c;
                              len=max(temp,len);
              }
              for(i=0;i<stick.size();i++)
              {
                                           if(stick[i]*stick[i]<=len)ctr++;
              }
              cout<<ctr<<endl;
    }
}

    
              
              
