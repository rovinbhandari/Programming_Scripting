#include<iostream>
#include<cmath>
using namespace std;
int main()
{
    int t;
    long n, m, count, i, j;
    long h,b,len;
    cin>>t;
    while(t--)
    {
          count = 0;
          cin>>n>>m;
          long l[n], max[m], max_value;
          for(i=0;i<n;i++)
            cin>>l[i];
          max_value = 0;
          for(j=0;j<m;j++){
            cin>>h>>len>>b;
            max[j] = (long)sqrt((h*h)+(b*b)+(len*len));
            if(max[j]>max_value)
               max_value = max[j];
          }
          for(i=0;i<n;i++)
          {
            if(l[i]<=max_value)
               count = count+1;
          }
          cout<<count<<endl;
    }

    return 0;
}
