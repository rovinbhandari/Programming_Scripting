#include <iostream>
#include <algorithm>
#include<cstdio> 
using namespace std;
int main()
{
    	int test,l,h,n,arr[1010];
    	scanf("%d",&test);
        while(test--)
	{
                scanf("%d%d%d",&n,&l,&h);
                for(int i=0;i<n;i++)
                scanf("%d",&arr[i]);
                sort(arr,arr+n);
                int y=n-1;
                int counter1=0,counter2=0;
                if(l==1)
                counter1=0;
                else
                {
	                for(int i=0;i<=n-3;i++)
	                {
		                for(int j=i+1;j<=n-2;j++)
		                {
		                        int d=j+1;
		                        int u=n-1;
		                        int mid;
	                       
		                        while(d<u)
		                        {
	                    	        	mid=(u+d)/2;
                                  		if((arr[i]+arr[j]+arr[mid])>(l-1))
                                  		{
                                  			u=mid-1;
                                  			continue;
                                  		}
                                  		else if((arr[i]+arr[j]+arr[mid])<=(l-1))
                                  		{
                                  			d=mid+1;
                                  			continue;
                                  		}
                        		}
                       			if((arr[i]+arr[j]+arr[d])>(l-1))
                       			d--;
                       
                        		counter1=counter1+d-j;
                		}
        		}
        	}

        	for(int i=0;i<=n-3;i++)
                {
                	for(int j=i+1;j<=n-2;j++)
                	{
                	        int d=j+1;
                	        int u=n-1;
                	        int mid;
                	        while(u>d)
                	        {
                                	mid=(u+d)/2;
                                  	if((arr[i]+arr[j]+arr[mid])>h)
                                  	{
                                  		u=mid-1;
                                  		continue;
                                  	}
                                  	else if((arr[i]+arr[j]+arr[mid])<=h)
                                  	{
                                  		d=mid+1;
                                  		continue;
                                  	}
                        	}
                        	if((arr[i]+arr[j]+arr[d])>h)
                       		d--;
                        	counter2+=d-j;
                	}
        	}
       
        	printf("%d\n",counter2-counter1);
  	}
return 0;
}
