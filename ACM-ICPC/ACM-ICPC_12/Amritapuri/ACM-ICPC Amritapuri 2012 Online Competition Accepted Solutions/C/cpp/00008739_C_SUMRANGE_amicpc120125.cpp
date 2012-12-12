#include<stdio.h>
#include<algorithm>

using namespace std;

int main(){
	int t,l,h,n;
	int a[1005];
	scanf("%d",&t);
	while(t--){
		scanf("%d%d%d",&n,&l,&h);
		for(int i=0;i<n;i++)
			scanf("%d",&a[i]);
		sort(a,a+n);
		int s=0;
		int end=0;
		int nl,nh;
		int ch=0;
		int cl=0;
		int ans=0;
		for(int k=n-1;k>=2;k--){
			s=0;
			end=k-1;
			nl=l-a[k];
			nh=h-a[k];
			ch=0;
			cl=0;
			//printf("nl =%d ,nh=%d\n",nl,nh);
			while(s !=end){
				if(a[s]+a[end]>nh)
					end--;
				else {
					ch+=(end-s);
					s++;

				}
			}
			s=0;
			end=k-1;
			while(s !=end){
				if(a[s]+a[end]>(nl-1))
					end--;
				else {
					cl+=(end-s);
					s++;
				}
			}
			//printf("cl =%d,ch=%d\n",cl,ch);
			ans+=(ch-cl);
		}
		printf("%d\n",ans);
	}	
	return 0;
}
