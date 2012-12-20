#include <iostream>
#include <cstdio>
#include <map>
#include <stack>
#include <queue>
#include <vector>
#include <list>
#include <string>
#include <algorithm>
#include <cmath>

using namespace std;
#define f(i,n) for((i)=0;(i)<(n);(i)++)

int main(int argc, char const *argv[])
{
	int i,j,k,x;
	scanf("%d",&x);
	int b[100001];
	int c[100001];
	//int d[100001];
	char a[100001];	
	
	f(k,x){
		vector<vector<int> > vec;
		int n;
		scanf("%d", &n);
		scanf("%s", a);
		b[0] = 0;

		for(i=1; i<=n; i++){
			if(a[i-1] == '0') b[i] = b[i-1] + 1;
			else b[i] = b[i-1];			
		}

		c[n] = 0;

		if(a[n-1] == '0') c[n-1] = 0;
		else c[n-1] = 1;

		for(i=n-2; i>=0 ;i--){
			if(a[i] == '0') c[i] = c[i+1];
			else c[i] = 1 + c[i+1];
			//d[i] = c[i] + b[i];
		}
		vector<int> tempvec;
		vec.push_back(tempvec);
		for(int sami = 0; sami <= n; sami ++) {
			
			vec[0].push_back(b[sami] + c[sami]);
			//printf("%d ", vec[0][sami]);
		}
		//printf("\n");
		int samn = n+1;
		int level = 0;
		while (samn > 1) {
			samn = samn/2;
			level++;
			vector<int> tempvec;
			vec.push_back(tempvec);
			for (int sami = 0; sami < samn; sami++) {
				vec[level].push_back(max(vec[level-1][sami*2], vec[level-1][sami*2 +1] ));
			//	printf("%d ",vec[level][sami]);
			}
			//printf("\n");
		}

		
		//d[n-1] = c[n-1] + b[n-1];
	//	d[n] = c[n] + b[n];
		/*
		f(i,n+1){
			printf("%d ", b[i]);
		}
		printf("\n");
		f(i,n+1){
			printf("%d ", c[i]);
		}
		printf("\n");
		*/

		/*for (int g = 0; g <= level; g++) {
			int leng = vec[g].size();
			for (int hj = 0; hj < leng; hj++) {
				printf("%d ", vec[g][hj]);
			}
			printf("\n");
		}*/
		
		int m;
		scanf("%d", &m);
		f(i,m){
			int a1, a2;
			scanf("%d %d", &a1, &a2);
			a1 -= 1; a2 -= 1;
			int ma = -1;

			int range = a2 - a1 + 2;
			int start = a1;
			while (range > 0) {
				int lvl = 0;
				int rng = 1;
				int str = start;
				while ((rng <= (range/2)) && ((str % 2) == 0) && (lvl < level)) {
					lvl++;
					rng *= 2;
					str = str / 2;
				}
				int newm = vec[lvl][str];
				//printf("lvl: %d, str: %d , rng: %d, start: %d\n",lvl, str, rng, start);
				if (newm > ma) {
					ma = newm;
				}
				range = range - rng;
				start = start + rng;
			}
			/*for(j=a1; j<=a2+1; j++){
				ma = max(ma, d[j]);
			}*/
			ma -= b[a1];
			if(a2 < n-1) ma -= c[a2+1];
			printf("%d\n", ma);
		}
	}
	return 0;
}
