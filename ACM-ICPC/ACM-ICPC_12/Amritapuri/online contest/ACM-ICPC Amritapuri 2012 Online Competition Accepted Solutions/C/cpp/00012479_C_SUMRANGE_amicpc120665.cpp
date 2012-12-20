#include<stdio.h>
#include<algorithm>
#include<algorithm>
#include<iostream>

using namespace std;
#define s(a) scanf("%d",&a);
#define p(a) printf("%d\n",a);
#define fr(n) for(i=0;i<n;i++)

int main()
{
	int t,i,j,k;
	int n,l,h;
	int x,y,z;
	int count;
	int a[1000];
	int s1,s2;
	s(t);
	while(t--)
	{
		count = 0;
		s(n);
		s(l);
		s(h);
		i = 0;
		for(i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		for(i=0;i<n-2;i++)		
		{
			x = a[i];
			for(j=i+1;j<n-1;j++)
			{
				y = x + a[j];
				if(y>h)
				{
					break;
				}
				for(k=j+1;k<n;k++)
				{
					z = y + a[k];
					if(z>h)
					{
						break;
					}
					else if((z>=l)&&(z<=h))
					{
						count++;					
					}
				}
			}
		}
		p(count);
	}
	return 0;	
}
