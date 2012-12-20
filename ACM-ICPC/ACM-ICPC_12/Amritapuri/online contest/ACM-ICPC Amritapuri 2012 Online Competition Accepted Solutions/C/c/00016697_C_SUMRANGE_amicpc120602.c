#include<stdio.h>
sort(int a[], int low, int high)
{
	int mid;
	if(low<high)
	{
	mid=(low+high)/2;
	sort(a,low,mid);
	sort(a,mid+1,high);
	merge(a,low,high,mid);
	}
	return(0);
}

merge(int a[], int low, int high, int mid)
{
	int i, j, k, c[1010];
	i=low;
	j=mid+1;
	k=low;
	while((i<=mid)&&(j<=high))
	{
	if(a[i]<a[j])
	{
	c[k]=a[i];
	k++;
	i++;
	}
	else
	{
	c[k]=a[j];
	k++;
	j++;
	}
	}
	while(i<=mid)
	{
	c[k]=a[i];
	k++;
	i++;
	}
	while(j<=high)
	{
	c[k]=a[j];
	k++;
	j++;
	}
	for(i=low;i<k;i++)
	{
	a[i]=c[i];
	}
}
binsearch(int a[],int first,int last,int search)
{
 int  middle = (first+last)/2;
   while( first <= last )
   {
      if ( a[middle] < search )
         first = middle + 1;    
      else if ( a[middle] == search ) 
      {
         return middle;
      }
      else
         last = middle - 1;
 
      middle = (first + last)/2;
   }
   return middle;
}
int main()
{
	int n,t,a[1000],l,r,i,p,q,j,k,mid,pre;
	long long int count;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&l,&r);
		count=0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,0,n-1);
		for(i=0;i<n-2;i++)
		{	
			for(j=i+1;j<n-1;j++)
			{
				p=l-a[i]-a[j];
				int x=j+1,y=n-1;
				x=binsearch(a,x,y,p);
				if(a[x]<p)
				x++;
				//printf("%d ",x);
				if(x<=j)
				{
					x=j+1;
				}
				q=r-a[i]-a[j];
				y=binsearch(a,j+1,n-1,q);
				if((a[i]+a[j]+a[y])<l)
				{
					y=-1;
					x=0;
				}
				//printf("%d ",y);
				if(y-x+1>0)
				count+=y-x+1;
				//printf("%d %d\n",x,y);
			}
		}
		printf("%lld\n",count);
	}
	return 0;
}
