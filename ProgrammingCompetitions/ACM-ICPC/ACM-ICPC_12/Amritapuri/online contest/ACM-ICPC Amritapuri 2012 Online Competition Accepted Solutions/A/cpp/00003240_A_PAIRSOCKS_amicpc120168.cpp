#include<iostream>
#include<cstdio>
using namespace std;

int main(){
	char arr[60];
	int i,T,R,G,B,W;
	cin>>T;
	while(T--){
		scanf("%s",arr);
		i=0;R=0;G=0;B=0;W=0;
		while(arr[i]!='\0'){
			if(arr[i]=='R')
				R++;
			if(arr[i]=='G')
				G++;
			if(arr[i]=='B')
				B++;
			if(arr[i]=='W')
				W++;
			i++;
		}
		if((R%2==0)&&(G%2==0) &&(B%2==0) &&(W%2==0))
			printf("YES\n");
		else
			printf("NO\n");
		
	}
	return 0;
}
