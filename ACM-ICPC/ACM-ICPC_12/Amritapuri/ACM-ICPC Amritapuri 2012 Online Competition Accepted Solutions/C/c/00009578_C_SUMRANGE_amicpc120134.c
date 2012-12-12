#include<stdio.h>
void mergesort(int a[],int low,int high);
void merge(int *a,int low,int mid,int high);
int ct=0;
int main()
{
	int tc;
	scanf("%d",&tc);
	while(tc--)
	{
		ct=0;
		int n,l,h;
		scanf("%d %d %d",&n,&l,&h);
		int a[n];
		int i;
		int min,max;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		mergesort(a,0,n-1);
		int j,k;
		int sum1,sum2;
		for(i=0;i<n-2;i++)
		{
			if(a[i]>h)
				break;
			for(j=i+1;j<n-1;j++)
			{
				sum1=a[i]+a[j];
				if(sum1>=h)
					break;
				for(k=j+1;k<n;k++)
				{
					sum2=sum1+a[k];
					if(sum2>h)
						break;
					else if(sum2<l)
						continue;
					else if(sum2>=l && sum2<=h)
						ct++;
				}
			}
		}
		printf("%d\n",ct);
	}
	return 0;
}
void mergesort(int a[],int low,int high)
{
	int mid=(low+high)/2;
	if(high-low<=0)
		return;
	mergesort(a,low,mid);
	mergesort(a,mid+1,high);
	merge(a,low,mid,high);
}
void merge(int *a,int low,int mid,int high)
{
	int len=high-low+1;
	int temp[len];
	int lp=low;
	int rp=mid+1;
	int k=0;
	while(lp<=mid && rp<=high)
	{
		if(a[lp]<=a[rp])
		{
			temp[k]=a[lp];
			lp++;
			k++;
		}
		else
		{
			temp[k]=a[rp];
			rp++;
			k++;
		}
	}
	while(lp<=mid)
	{
		temp[k++]=a[lp++];
	}
	while(rp<=high)
	{
		temp[k++]=a[rp++];
	}
	int i=0;
	for(i=0;i<len;i++)
	{
		a[i+low]=temp[i];
	}
}

