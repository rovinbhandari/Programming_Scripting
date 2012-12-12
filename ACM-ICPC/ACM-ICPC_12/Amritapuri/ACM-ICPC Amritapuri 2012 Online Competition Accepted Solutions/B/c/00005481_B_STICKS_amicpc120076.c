#include <stdio.h>
int main()
{
	int tc;
	scanf("%d",&tc);
	int i;
	for (i = 0; i < tc; i++)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		long long int l[50005], x[50005], y[50005], z[50005];
		int j;
		for (j = 0; j < n; j++)
		{
			scanf("%d",&l[j]);
		}
		long long int maxd=-1, temp;
		for (j = 0; j < m; j++)
		{
			scanf("%d%d%d",&x[j],&y[j],&z[j]);
			temp = x[j]*x[j]+y[j]*y[j]+z[j]*z[j];
			if (temp>maxd)
			{
				maxd = temp;
			}
		}
		int count = 0;
		long long int len;
		for (j = 0; j < n; j++)
		{
			len=l[j]*l[j];
			if(len<=maxd){
				count++;
			}
		}
		printf("%d\n", count);
		
	}
	
	return 0;
}
