#include<cstdio>
#include<set>
#include<iostream>
#include<algorithm>
using namespace std;

int main(){
	int T,N,L,H,a[1000],i,temp,count,count1,j;
	cin>>T;
	while(T--){
		count=0;
		count1=0;
		cin>>N>>L>>H;
		for(i=0;i<N;i++)
			scanf("%d",&a[i]);
		sort(a,a+N);
/*		for(i=0;i<N;i++)
			printf("%d ",a[i]);
		printf("\n");*/
		for(int k=0;k<N;k++){
			for(i=k+1,j=N-1;i<j;){
				temp=a[i]+a[j]+a[k];
				if(temp<=H){
					count+=j-i;
//					printf("%d,%d,%d\n",i,j,k);	
					i++;
				}
				else
					j--;
			}
		}
//		printf("--------\n");
		for(int k=0;k<N;k++){
			for(i=k+1,j=N-1;i<j;){
				temp=a[i]+a[j]+a[k];
				if(temp<L){
					count1+=j-i;
//					printf("%d,%d,%d\n",i,j,k);	
					i++;
				}
				else
					j--;
			}
		}
		printf("%d\n",count-count1);
	}
	return 0;
}
