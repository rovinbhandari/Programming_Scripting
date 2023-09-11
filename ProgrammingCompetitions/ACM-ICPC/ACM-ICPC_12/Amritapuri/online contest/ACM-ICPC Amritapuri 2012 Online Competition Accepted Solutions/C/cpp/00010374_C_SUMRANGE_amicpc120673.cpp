#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
int main()
{
	int t,i,j,sum,low1,low2;
	cin>>t;
	while(t--){
		sum = 0;
		int n,l,h,*low1,*low2;
		cin>>n>>l>>h;
		int a[n];
		for(i = 0; i < n; i++){
			cin>>a[i];
		}
		sort(a,a+n);
		for(i = 0; i < n-2;i++){
			for(j = i+1; j < n-1; j++) {
				low1 = lower_bound(a+j+1,a+n,l-a[i]-a[j]);
				low2 = upper_bound(a+j+1,a+n,h-a[i]-a[j]);
			//	printf("%d %d %d %d\n",a[i],a[j],*low1,*low2);
				 sum = sum + low2-low1;
		//		 cout<<sum<<endl;
			}
		}
		cout<<sum<<endl;
	}
}
