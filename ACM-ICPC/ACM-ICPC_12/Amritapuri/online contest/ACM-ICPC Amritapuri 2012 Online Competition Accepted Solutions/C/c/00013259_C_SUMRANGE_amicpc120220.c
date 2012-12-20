#include<stdio.h>
int compare (const void * a, const void * b)
{
	  return ( *(int*)b - *(int*)a );
}
int main()
{
	int arr[10006],n,t,L,H,i,j,k,count,ch,sum,lowest;
	scanf("%d",&t);
	while(t>0)
	{
		count=0;
		scanf("%d %d %d",&n,&L,&H);
		for(i=0;i<n;i++)
		{
			scanf("%d",&arr[i]);
		}
		 qsort (arr, n, sizeof(int), compare);
//for(i=0;i<n;i++)printf("%d ",arr[i]);printf("\n");		 
		for(i=0;i<=n-3;i++)
		{	lowest=L;
			if((arr[i]+arr[i+1]+arr[i+2])<lowest)break;
			ch=H;
			if(arr[i]>=H)continue;
			lowest=lowest-arr[i];
			for(j=i+1;j<=n-2;j++)
			{
				if(arr[j]+arr[j+1]<lowest)break;
				ch = H - arr[i];
				if(arr[j]>=ch)continue;
				for(k=j+1;k<=n-1;k++)
				{
					ch=H - arr[i]-arr[j];
					if(arr[k]>ch)continue;
					
						sum=arr[i]+arr[j]+arr[k];
						if(sum>=L)
						{
//							printf("%d %d %d\n",arr[i],arr[j],arr[k]);
							count++;
						}
					
				}
			}
		}
		printf("%d\n",count);
		t--;
	}
	return 0;
}

