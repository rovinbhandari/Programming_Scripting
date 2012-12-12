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
	int i,j,k,l,x;
	scanf("%d",&x);
	f(l,x){
		vector<int> x;
		int n,l,h;
		scanf("%d %d %d",&n, &l, &h);
		f(i,n){
			int temp;
			scanf("%d", &temp);
			x.push_back(temp);
		}
		sort(x.begin(), x.end());
		int count1 = 0;
		f(i,n-2){
			j = i+1;
			k = n-1;
			while(j < k){
				int S = x[i] + x[j] + x[k];
				if(S <= h) {
					count1 += k - j;
					j += 1;
				} else if (S > h) {
					k -= 1;
				}
			}
		}
		int count2 = 0;
		f(i,n-2){
			j = i+1;
			k = n-1;
			while(j < k){
				int S = x[i] + x[j] + x[k];
				if(S < l) {
					count2 += k - j;
					j += 1;
				} else if (S >= l) {
					k -= 1;
				}
			}
		}
		printf("%d\n", count1 - count2);
	}
	return 0;
}

