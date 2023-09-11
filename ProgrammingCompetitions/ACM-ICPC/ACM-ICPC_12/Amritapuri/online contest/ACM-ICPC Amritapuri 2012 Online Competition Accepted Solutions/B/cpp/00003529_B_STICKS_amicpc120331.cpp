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
	int an[50001];
	f(k,x){
		int m,n;
		scanf("%d %d", &n, &m);
		f(i,n){
			int temp;
			scanf("%d", &temp);
			an[i] = temp;
		}
		double t = 0;
		double l1;
		double l2;
		double l3;
		f(i,m){
			scanf("%lf %lf %lf", &l1, &l2, &l3);
			t = max(t, sqrt(l1*l1 + l2*l2 + l3*l3));
		}
		int count = 0;
		f(i,n){
			if(an[i] <= t) count += 1;
		}
		printf("%d\n", count);
	}
	return 0;
}
