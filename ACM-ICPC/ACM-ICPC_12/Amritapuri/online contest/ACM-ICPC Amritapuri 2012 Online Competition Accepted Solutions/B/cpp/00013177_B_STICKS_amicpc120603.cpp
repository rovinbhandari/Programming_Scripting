#include<iostream>
#include<math.h>
using namespace std;

int main()
{
        long int t,m,n,l[50001],len,b,h,i,max,count,diagonal;
        cin>>t;
        while(t--)
        {
                max=0;
                count=0;
  		cin>>n>>m;      
                for(i=0;i<n;i++)
                        cin>>l[i];
                for(i=0;i<m;i++)
                {
            		cin>>len>>b>>h;
                        diagonal=len*len+b*b+h*h;
                        if(diagonal>max) max=diagonal;
                }
                for(i=0;i<n;i++)
                {
                     if(l[i]*l[i]<=max)       
                                count++;
                }
                cout<<count<<"\n";
        }
        return 0;
}
