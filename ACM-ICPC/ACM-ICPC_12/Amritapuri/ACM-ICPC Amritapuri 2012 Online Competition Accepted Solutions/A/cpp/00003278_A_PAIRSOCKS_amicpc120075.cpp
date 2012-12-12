#include<cstdio>
#include<cstdlib>
#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>
#include<queue>
#include<set>
#include<cstring>
#include<string>
#include<cmath>
using namespace std;
int main(){
	int T,i,j,a[4];
	char str[100];
	scanf("%d",&T);
	while (T--){
		a[0]=a[1]=a[2]=a[3]=0;
		scanf("%s",str);
		j=strlen(str);
		for (i=0;i<j;i++){
			if (str[i]=='R') a[0]++;
			else if (str[i]=='G') a[1]++;
			else if (str[i]=='B') a[2]++;
			else a[3]++;
		}
//		printf("%d %d %d %d\n",a[0],a[1],a[2],a[3]);
		if ((a[0]%2==0) and (a[1]%2==0) and (a[2]%2==0) and (a[3]%2==0)) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}
