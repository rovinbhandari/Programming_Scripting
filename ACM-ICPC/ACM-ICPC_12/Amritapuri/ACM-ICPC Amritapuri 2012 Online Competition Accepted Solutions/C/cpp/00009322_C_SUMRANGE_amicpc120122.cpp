#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;
int main(){

	int i,j,k;
	int n,l,h;
	int T;
	int a[1001];
	int newn;
	scanf("%d",&T);
	int cnt;
	while(T--){
		cnt = 0;
		scanf("%d%d%d",&n,&l,&h);
		for(i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		sort(a,a+n);
		i = n -1;
		while(a[i] > h)
			i--;
		n = i + 1;
		i = n - 1;
		while(a[i] + a[0] > h){
			n--;
			i--;
		}
		for(i=0;i<n;i++){
			for(j=i+1;j<n;j++){
				if(a[i] + a[j] > h)
					break;
				for(k=j+1;k<n;k++){
					if(a[i] + a[j] + a[k] > h)
						break;
					if(a[i] + a[j] + a[k] <= h && a[i] + a[j] + a[k] >=l)
						cnt++;
				}
			}

		}	
		printf("%d\n",cnt);
	}

	return 0;
}
