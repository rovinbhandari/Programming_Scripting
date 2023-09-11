
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>


using namespace std;

long long int l[50001];

int main() {
	int test;
	scanf("%d",&test);
	while(test--){
		int n,m,count=0,f=0;
		scanf("%d %d",&n,&m);
		long long int max=0,val;
		for(int i=0;i<n;i++){
			//fin>>l[i];
			scanf("%lld",&l[i]);
		}
		long long int a,b,c;
		for(int i=0;i<m;i++){
			//fin>>a>>b>>c;
			scanf("%lld %lld %lld",&a,&b,&c);
			val=a*a + b*b + c*c;
			if(max < val){
				max=val;
				f=1;
			}
			else if(max==val)
				f++;
		}
		for(int i=0;i<n;i++){
			val=l[i]*l[i];
			if(val<max)
				count++;
			else if(val==max)
				if(f){
					f--;
					count++;
				}
		}
		printf("%d\n",count);
	}
	return 0;
}
