#include<iostream>
using namespace std;
int main()
{
 	long t,a,b,c,i,count,x=0,max,max1;
 	long n,m,*l;
 	cin>>t;
 	while(x<t)
 	{
	count=0; 		  
 	cin>>n>>m;
 	l=new long[n];
 	for(i=0;i<n;i++)
 	cin>>l[i];
 	 max=0;
 	for(i=0;i<m;i++)
 	{
	 				
 					cin>>a>>b>>c;
 					 max1=(a*a)+b*b+c*c;
 					 if(max1>max)
 					 {
	 				  			 max=max1;
					}
		}
		for(i=0;i<n;i++)
		{
		 				if(l[i]*l[i]<=max)
		 				{
						 				  count++;
						}
		}
	
		cout<<count<<"\n";
		x=x+1;
	}
		
		return 0;

}
		
