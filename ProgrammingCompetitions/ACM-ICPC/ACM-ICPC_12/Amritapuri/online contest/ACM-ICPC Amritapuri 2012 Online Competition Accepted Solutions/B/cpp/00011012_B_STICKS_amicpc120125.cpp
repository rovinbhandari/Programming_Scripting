#include<stdio.h>
#include<math.h>
#include<iostream>
using namespace std;
int main(){
	int t,n,m;
	long long int stick[50005];
	long long int len[50005],br[50005],ht[50005];
	scanf("%d",&t);
	while(t--){
		scanf("%d%d",&n,&m);
		for(int i=0;i<n;i++){
			scanf("%lld",&stick[i]);
		}
		long long int d = 0;
		long long int max = 0;
		for(int i=0;i<m;i++){
			scanf("%lld %lld %lld",&len[i],&br[i],&ht[i]);
		
			d = len[i]*len[i];
			d += br[i]*br[i];
			d+= ht[i]*ht[i];
			
			if(i == 0){
				max = d;
			}
			else{
				if(max < d){
					max = d;
				}
			}

		}
		int ans=0;
		int flag = 0 ;
		long long int temp = 0;
		for(int i=0;i<n;i++){
			temp = stick[i]*stick[i];
			if( max >= temp){
				ans++;
			}
	/*		else if(temp == max){
				if(flag == 0){

					ans++;
					flag = 1;
				}
			}*/
		}
		printf("%d\n",ans);
	}
	return 0;
}
