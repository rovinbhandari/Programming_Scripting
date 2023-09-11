#include<stdio.h>
long long int temp;
void upsort(long long int a[],long long int n)
{
	if(n==0)
		return;
	if(a[((n+1)/2)-1]>a[n])
	{
		temp=a[n];
		a[n]=a[((n+1)/2)-1];
		a[((n+1)/2)-1]=temp;
		temp=((n+1)/2)-1;
		upsort(a,temp);
	}
	return;
}
void downsort(long long int a[],long long int n,long long int i)
{
	if((2*(i+1))>n)
		return;
	if(((2*i)+1)==n-1)
	{
		if(a[(2*i)+1]<a[i])
		{
			temp=a[(2*i)+1];
			a[(2*i)+1]=a[i];
			a[i]=temp;
		}
		return;
	}
	if(a[(2*i)+1]<a[(2*i)+2])
	{
		if(a[i]>a[(2*i)+1])
		{
			temp=a[(2*i)+1];
			a[(2*i)+1]=a[i];
			a[i]=temp;
			downsort(a,n,((2*i)+1));
		}
	}
	else
	{
		if(a[i]>a[(2*i)+2])
		{
			temp=a[(2*i)+2];
			a[(2*i)+2]=a[i];
			a[i]=temp;
			downsort(a,n,((2*i)+2));
		}
	}
	return;
}
int main()
{
	long long int test,lp;
	scanf("%lld",&test);
	for(lp=0;lp<test;lp++)
	{
		long long int i,j,k,a[1000006],n,l,h;
		scanf("%lld%lld%lld",&n,&l,&h);
		for(i=0;i<n;i++)
		{
			scanf("%lld",&a[i]);
			upsort(a,i);
		}
		long long int c[n],answer=0;
		for(i=n;i>0;i--)
		{
			c[n-i]=a[0];
			a[0]=a[i-1];
			downsort(a,i-1,0);
		}
		for(i=0;i<n;i++)
		{
			if(c[i]>=h)
				break;
			for(j=i+1;j<n;j++)
			{
				if(c[i]+c[j]>=h)
					break;
				for(k=j+1;k<n;k++)
				{
					if(c[i]+c[j]+c[k]<=h && c[i]+c[j]+c[k]>=l)
						answer++;
					else if(c[i]+c[j]+c[k]>h)
						break;
				}
			}
		}
		printf("%lld\n",answer);
	}
	return 0;
}
