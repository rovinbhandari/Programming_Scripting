#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int searchFirst(int x[],int a,int b,int key)
{
	int k;
	int res = -1;
	while(a <= b){
		k = (a+b)/2;
		if(x[k] >= key){
			b = k - 1;
			res = k;			
		}else{
			a = k + 1 ;
		}
	}
	
	return res;
}

int searchLast(int x[],int a,int b,int key)
{
	int k;
	int res = -1;
	while(a <= b){
		k = (a+b)/2;
		if(x[k] <= key){
			a = k +1;
			res = k;
		}else{
			b = k -1 ;
		}
	}
	
	return res;
}

int main( )
{
	int t,n,L,H;
	int a[1010];
	
	scanf("%d",&t);
	
	while(t--){
		scanf("%d%d%d",&n,&L,&H);
			
		for(int i=0;i<n;i++){
			scanf("%d",&a[i]);
		}
		
		sort(&a[0],&a[n]);
		
		int res = 0;

		for(int i=0;i<n-2;i++){
			for(int j=i+1;j<n-1;j++){
				if(a[i]+a[j]+a[j+1]>H){
					continue;
				}
				if(a[i]+a[j]+a[n-1]<L){
					continue;
				}
									
				int p,q;
				
				if(a[i]+a[j]+a[j+1]>=L){
					p = j+1;
				}else{	
					p = searchFirst(a,j+1,n-1,L-a[i]-a[j]);
				}
				
				if(a[i]+a[j]+a[n-1]<=H){
					q = n-1;
				}else{			
					q = searchLast(a,j+1,n-1,H-a[i]-a[j]);				
				}
					
				if(q<0 || p<0)
					continue;
				
				if(q<p){
					continue;
				}else{	
					res = res + (q-p+1);
				}
			}
		}
		
		cout<<res<<endl;
	}
	
	return 0;
}


		