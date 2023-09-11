#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <math.h>

using namespace std;

int main(int argc, char** argv)
{
	int t;
	scanf("%d", &t);

	int n,m;
	int length[1000000];
	int a[100000];
	int b[100000];
	int c[100000];
	int max[100000];
	int i,j,k;
	while(t>0)
	{

	scanf("%d %d",&n,&m);
		int ans=0;
		long long int max1=0;
		for(i=0;i<n;i++){
			scanf("%d",&length[i]);
		}
		for(i=0;i<m;i++){

			scanf("%d %d %d",&a[i],&b[i],&c[i]);
			long long int temp = a[i]*a[i];
			temp += b[i]*b[i];
			temp += c[i]*c[i];
			max[i] = sqrt(temp);
			long long temp1 = sqrt(temp);
			//printf("%lld", temp1);
			if(temp1>=max1)max1=temp1;
		}
		
		for(i=0;i<n;i++){

			if(length[i]<=max1)ans++;
		}
		printf("%d\n",ans);
		t--;
	}

	return 0;
}

