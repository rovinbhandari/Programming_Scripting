#include<iostream>
#include<math.h>
using namespace std;
main()
{
     long long int n,count,t,i,m,k,l,b,h,arr[50000],temp,max;
      cin>>t;
      for(i=0;i<t;i++)
      {
                      count=0;
                      cin>>n>>m;
                      for(k=0;k<n;k++)
                        cin>>arr[k];
                      
                      for(k=0;k<m;k++)
                  {      cin>>l>>b>>h;
                        
                        temp=pow(l,2)+pow(b,2)+pow(h,2);
                        
                        temp=sqrt(temp);
                        if(k==0)
                            max=temp;
                        if(temp>max)
                           max=temp;
                           
                  }
                  for(k=0;k<n;k++)
                   {   if(arr[k]<=max)
                         count++;
                   }     
                   cout<<count<<"\n";

                  
}                        
                        
      
                  
}
       
