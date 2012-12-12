#include<iostream>
#include<vector>
#include<string>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<cstdlib>
using namespace std;
int compareints(const void *a,const void *b)
{
	return (*(int*)a - *(int*)b);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--){
		int L,H,n;
		scanf("%d%d%d",&n,&L,&H);
		int a[n];
		int i,num,j;
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		vector <int> arr(a,a+n);
		vector<int> :: iterator low,up;
		int count =0;
		for(i=0;i<n-1;i++){
			int sum = arr[i];
			if(L-sum > arr[n-1]+arr[n-2])
				break;
			else if(H-sum <arr[i+1]+arr[i+2])
				break;
			for(j=i+1;j<n;j++){
				sum += arr[j];
				low = lower_bound(arr.begin()+j+1,arr.end(),L-sum);
				up = upper_bound(arr.begin()+j+1,arr.end(),H-sum);
				count+=int(up-low);
				sum = arr[i];
				
			}
		}
		printf("%d\n",count);
	}
	return 0;
}
