#include<iostream>
#include<algorithm>


using namespace std;

int main()
{
    
long int a[1000],l,h,count[100];
int t,yo=0;
int i,j,k,m,n;

cin>>t;

for(m=0;m<t;m++) 
{
                 count[yo]=0;
cin>>n>>l>>h;

for(i = 0; i<n;i++)
cin>>a[i];
sort(a,a+n);



for(i=0;i<n-2;i++)
	{
    if(a[i] >h)
    break;    
            
	for(j=i+1;j<n-1;j++)
		{
        if(a[i]+a[j]>h)
            break;   
                          
		for(k=j+1;k<n;k++)
			{
            if(a[i]+a[j]+a[k] >h)
            break;              
              
			if((a[i]+a[j]+a[k])>= l && (a[i]+a[j]+a[k] <=h))
				{count[yo]++;}
			}
		}
	}
yo++;

}

for(m=0;m<t;m++)
cout<<count[m]<<'\n';


}
