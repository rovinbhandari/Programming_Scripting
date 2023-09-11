#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main ()
{
	int i,j,k,m,n,l,h,p;
	scanf ("%d",&m);
	while (m--){
		scanf ("%d%d%d",&n,&l,&h);
		int a[n];
		int q=0;
		int b[1000000];
		for (i=0;i<n;i++){
			scanf ("%d",&p);
			if (p<(h-1)){
				a[q++]=p;
			}
		}
		sort(a,a+q);
		int count =0;
		for (i=0;i<q-2;i++){
			for (j=i+1;j<q-1;j++){
				for (k=j+1;k<q;k++){
					if (((a[i]+a[j]+a[k])>=l)&&((a[i]+a[j]+a[k])<=h)){
							count++;
					}
					if ((a[i]+a[j]+a[k])>h){
						break;
					}
				}
			}
		}
		cout << count << "\n";
	}
		return 0;
}
				
