#include<iostream>
#include<stdio.h>
#include<math.h>
using namespace std;

int main()
{

	int t;
	int n,m;
	int h,l,w;
	int i,count;
	unsigned long long int temp;
	int temp2;
	int max;
	scanf("%d",&t);
	while(t--)
	{
		count=0;
		scanf("%d%d",&n,&m);
		int *a=new int [n];
		for(i=0;i<n;i++)
			scanf("%d",&a[i]);
		scanf("%d%d%d",&h,&l,&w);
		temp=h*h;
			temp += l*l ;
			temp+= w*w;
		max=sqrt(temp);
		for(i=1;i<m;i++)
		{
			scanf("%d%d%d",&h,&l,&w);
			temp=h*h;
			temp += l*l ;
			temp+= w*w;
			temp2=sqrt(temp);
			if(temp2>max)
				max=temp2;
		}
		for(i=0;i<n;i++)
		{
			if(a[i]<=max)
			{
				count++;
			}
		}
		printf("%d\n",count);
		delete [] a;
	}
	return 0;
}
