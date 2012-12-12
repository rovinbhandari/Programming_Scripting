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
#include <cstdlib>
#include <cstring>
using namespace std;
#define f(i,n) for((i)=0;(i)<(n);(i)++)

int main(int argc, char const *argv[])
{
	int i,j,k,x;
	scanf("%d",&x);
	char a[60];
	f(k,x){
		scanf("%s", a);
		int le = strlen(a);
		int a1, a2, a3, a4;
		a1 = 0;
		a2 = 0; 
		a3 = 0;
		a4 = 0;
		f(i,le){
			if(a[i] == 'R') a1 += 1;
			if(a[i] == 'G') a2 += 1;
			if(a[i] == 'B') a3 += 1;
			if(a[i] == 'W') a4 += 1;
		}
		if(a1%2==0 && a2%2==0 && a3%2 == 0 && a4%2==0) {
			printf("YES\n");
		} else {
			printf("NO\n");
		}
	}
	return 0;
}
