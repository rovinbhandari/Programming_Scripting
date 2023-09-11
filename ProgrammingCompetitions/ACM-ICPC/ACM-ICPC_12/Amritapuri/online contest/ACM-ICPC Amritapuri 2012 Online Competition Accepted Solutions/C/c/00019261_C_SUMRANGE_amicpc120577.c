#include <stdio.h>
#include<stdlib.h>
int a[1000];
int compare(const void * a,const void * b)
{
  return(*(int *)a - *(int *)b);
}

int main()
{
  int t,l,h,n,i,j,k,s,i1,j1,t1;
  int cnt=0;
  scanf("%d",&t);
  while(t--)
  {
	  cnt=0;
	  scanf("%d%d%d",&n,&l,&h);
	  for(i=0;i<n;++i)
		scanf("%d",&a[i]);
	  qsort(a,n,sizeof(int),compare);
	  
	  i=0;
	  j=1;
	  k=n-1;
	  while(j<k)
	  {
		t1=k-j;
		for(i1=0;i1<t1;++i1)
		{
			for(j1=0;j1<=i1;++j1)
			{
				s=a[i]+a[j+j1]+a[k+j1];
				//printf("\nI %d J %d K %d S %d",i,j+j1,k+j1,s);
				if(s>h)
				  break;
				else if(s>=l)
				  ++cnt;
			  }
			  k--;
		}
		++i;
		j=i+1;
		k=n-1;
	  }
	  printf("%d\n",cnt);
  }
  
  return 0;
}
