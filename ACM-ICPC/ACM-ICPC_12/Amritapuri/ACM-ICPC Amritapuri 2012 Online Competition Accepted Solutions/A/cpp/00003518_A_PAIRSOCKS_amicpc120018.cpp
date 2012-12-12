#include<iostream>
#include<math.h>
#include<stdio.h>
#include<vector>
#include<map>
#include<string>
#include<algorithm>
#define x getchar_unlocked()
#define y putchar_unlocked
using namespace std;	
int main() {
	int t,A[4]={0};
	char ch;
	scanf("%d\n",&t);
	while(t--) {
		ch=x;
		while(ch!='\n') {
			if(ch=='R')A[0]++;
			else if(ch=='G')A[1]++;
			else if(ch=='B')A[2]++;
			else A[3]++;
			ch=x;
			}
		int i=0;
		for(;i<4;i++) {
			//cout<<A[i]<<endl;
			if(A[i]%2==1) break;
			}
		if(i==4) printf("YES\n");
		else printf("NO\n");
		for(i=0;i<4;i++)
			A[i]=0;
		}
	return 0;
	}
