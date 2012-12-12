#include<iostream>


using namespace std;
long long int arr[50001];


int main()
{
   
   long long int t,n,m,a,b,c,k,max,count;
   
   cin>>t;
   while(t--)
   {
             max=0;
             count = 0;
             cin>>n>>m;
             
            for(int i=0;i<n;i++)
            {
                    cin>>arr[i];
            }
            
            for(int i=0;i<m;i++)
            {
                    cin>>a>>b>>c;
                     
                     k=(a*a+b*b+c*c);
                     
                    if(max<k)
                    max=k;
            }
            //cout << max;
            
            
            for(int i=0;i<n;i++)
            {
                    if((arr[i]*arr[i])<=max)
                    count++;
            }
   
   cout<<count<<endl;         
   
   }        
            
            
   }
