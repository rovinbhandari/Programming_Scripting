#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

int main()
{
      int n,m,t2;
      cin>>t2;
      int a[50000];
      double b[50000][3],max;
      int count=0;
      double t1[50000];
      int t;
      
      while(t2--)
      {
      count=0;
      cin>>n;
      cin>>m;
      for(int i=0;i<n;i++)
      cin>>a[i];        
      
      for(int i=0;i<m;i++)  
      {        
          cin>>b[i][0]>>b[i][1]>>b[i][2];
          t1[i]=sqrt((b[i][0]*b[i][0]) + (b[i][1]*b[i][1]) + (b[i][2]*b[i][2]));
      }
      
      sort(t1,t1+m);
      max=t1[m-1];
      
      for(int i=0;i<n;i++)
      if(a[i]<=max)  
      count++;
              
      cout<<count<<endl;
     }
     
      return 0;
}
