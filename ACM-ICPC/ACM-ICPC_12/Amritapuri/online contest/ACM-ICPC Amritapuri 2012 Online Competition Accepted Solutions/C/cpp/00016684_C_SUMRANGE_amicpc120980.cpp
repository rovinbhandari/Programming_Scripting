#include<stdio.h>
#include<string>
#include<iostream>
#include<math.h>
#include<vector>
#include<algorithm>

using namespace std;

#define s(a) scanf("%d",&a)
#define fr(i,j,k) for(i=j;i<=k;i++)

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
	int t;
	s(t);
	while(t--){
		int i,n,l,h,size;
		vi a;
		s(n);
		s(l);s(h);
		size = n;
		while(n--){
			int o;s(o);
			a.push_back(o);
		}
		sort(a.begin(),a.end());
		
		int j,k;
		long long sum = 0;
		long long count = 0;
		fr(i,0,size-1){
			k = i+1;
			j = size-1;
			while(k < j){
				if(a[i]+a[j]+a[k] > h)
					j--;
				else{
					if(a[i]+a[j]+a[k] < l)
						k++;
					else{
						for(int f=k;f < j ; f++){
							if(a[i]+a[j]+a[f] <= h)
								count += 1;
							else break;
						}
						j--;
					}
				}
			}
		}
		printf("%lld\n",count);
	}
}
