#include<iostream>
using namespace std;
int main()
{     int t;
      cin>>t;
      while(t--)
      {         int n,l,h;
                cin>>n>>l>>h;
                int a[n];
                for(int i=0;i<n;i++)
                        cin>>a[i];
                        

                for(int i=0;i<n-1;i++)            //bubble sorting
            	{       for(int j=0;j<n-1-i;j++)  
                    		if(a[j]>a[j+1])
                    		{   	int temp=a[j];
                    			a[j]=a[j+1];
                    			a[j+1]=temp;
                    		}
            	}

            	for(int i=0;i<=n;i++)
                   if(a[i]>h)
                               {n=i; break;}
                
                int ctr=0;
                 for(int i=0;i<n;i++)
                  for(int j=i+1;j<n;j++)
                    for(int k=j+1;k<n;k++)
                     {
                            if(a[i]+a[j]+a[k]>=l)
                             if (a[i]+a[j]+a[k] <=h)
                             ctr++;
                             else break;
                     }
                             
                             cout<<ctr<<"\n";
      }
      return 0;
}
      
