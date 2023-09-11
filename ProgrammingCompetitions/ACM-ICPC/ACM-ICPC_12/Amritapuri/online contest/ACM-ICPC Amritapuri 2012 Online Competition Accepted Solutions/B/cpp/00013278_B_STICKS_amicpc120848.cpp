#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <stdio.h>
#include <math.h>
#include <algorithm>
using namespace std;


int main(){
    int t;
    scanf("%d",&t);
	double ns[50002];
	
    for(int i=0; i<t; i++){
		
		int n,m;
        double max1 = 0; 
		
        scanf("%d",&n);
		scanf("%d",&m);
        
        for(int j=0; j<n; ++j){
            scanf("%lf",(ns+j));
        }
        for(int j=0; j<m; ++j){
			double l1,l2,l3;
			scanf("%lf",&l1);
			scanf("%lf",&l2);
			scanf("%lf",&l3);
            max1= max(max1, sqrt(l1*l1 + l2*l2 + l3*l3));
            //printf("val = %d\n",temp);
        }
		
		int count = 0;
        for(int j=0; j<n; ++j){
            if(ns[j] <= max1){
				count++;
			}
        }
        printf("%d\n",count);   
    }
    return 0;
	
}