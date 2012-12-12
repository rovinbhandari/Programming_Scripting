#include<stdio.h>
#include<string>
#include<iostream>
#include<math.h>
#include<vector>

using namespace std;

#define s(a) scanf("%d",&a)
#define fr(i,j,k) for(i=j;i<=k;i++)

typedef vector<int> vi;
typedef vector<vi> vvi;

int main(){
	int t;
	s(t);
	while(t--){
		string a;
		cin >> a;
		int i;
		int n[4]={0};
		fr(i,0,a.length()-1){
			switch(a[i]){
				case 'R':
					n[0]++;break;
				case 'G':
					n[1]++;break;
				case 'B':
					n[2]++;break;
				case 'W':
					n[3]++;break;
			}
		}
		int k = 0;
		fr(i,0,3){
			if(n[i] % 2 != 0)
				k = 1;
		}	
		if(k == 0 ) printf("YES\n");
		else printf("NO\n");
	}
}
