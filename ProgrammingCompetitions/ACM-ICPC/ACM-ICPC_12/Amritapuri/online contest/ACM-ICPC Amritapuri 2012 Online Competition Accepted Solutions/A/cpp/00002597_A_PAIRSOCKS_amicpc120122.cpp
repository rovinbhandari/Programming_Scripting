#include<stdio.h>
#include<iostream>
#include<math.h>
#include<stdlib.h>
using namespace std;
int main(){

	int r,g,b,w;
	int T;
	char ip[100];
	int i;
	scanf("%d",&T);

	while(T--){
		i = 0;
		r = 1;
		g = 1;
		b = 1;
		w = 1;
		scanf("%s",ip);
		while(ip[i]!='\0'){
			if(ip[i] == 'R')
				r *= -1;
			else if(ip[i] == 'G')
				g *= -1;
			else if(ip[i] == 'B')
				b *= -1;
			else if(ip[i] == 'W')
				w *= -1;
			i++;
		}
		if(r == 1 && b == 1 && w == 1 && g == 1)
			printf("YES\n");
		else
			printf("NO\n");
		
	}
	return 0;
}
