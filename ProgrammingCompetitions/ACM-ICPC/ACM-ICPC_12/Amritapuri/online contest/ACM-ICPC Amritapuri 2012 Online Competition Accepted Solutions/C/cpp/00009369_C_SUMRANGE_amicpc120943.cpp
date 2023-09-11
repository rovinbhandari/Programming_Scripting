#include <iostream>
#include <cstdlib>

using namespace std;



int compare (const void *elem1, const void *elem2)
{
    return *(int*)elem1 - *(int*)elem2;
}



int main(){

int t,n,l,r;
cin>>t;

int c;

	for(int z=0;z<t;z++)
	{
		cin>>n>>l>>r;
		int a[n];
		c=0;
		for(int i=0;i<n;i++)
		{
			cin>>a[i];

		}
	
		 qsort(a, n, sizeof(int), compare);
	
		for(int i=0;i<n;i++)
		{
		     int j=(n-1);
		      while (a[i]+a[j]>r)
			       j--;
			       
	             for(int y=(j);y>i;y--)		       
			{       
				      int p=a[i]+a[y];
			     
				 for(int k=(i+1);k<y;k++)
				 {		      
				      if(p+a[k]<l)
				       continue;
				       
				       if(p+a[k]>r)
				       break;
				       
				       //if(k!=j && k!=i)
				       c++;
				
			    		
			    	 }
			 }   	 
		}
	
		cout<<c<<endl;
	}

}


