#include <iostream>
#include <cmath>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(){
	int t, n, m, tot;int ar[100000];
	long long a,b,c;
	scanf("%d", &t);
	while(t--){
		scanf("%d %d", &n, &m);
		for(int i = 0; i < n; i++){
			scanf("%d", &ar[i]);
		}
		
		tot = 0;
		 for(int i = 0; i < m; i++){
                        scanf("%lld %lld %lld", &a, &b,&c);
			tot = max(tot,(int)sqrt(a*a+b*b+c*c));
		}
		int ret = 0;
		 for(int i = 0; i < n; i++){
                        if(ar[i] <= tot){ret++;}
                }
		printf("%d\n", ret);
	
	}
return 0;
}

