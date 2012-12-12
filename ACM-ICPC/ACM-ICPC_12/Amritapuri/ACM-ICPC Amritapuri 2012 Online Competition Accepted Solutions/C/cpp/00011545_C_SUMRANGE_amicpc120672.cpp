#include<cstdlib>
#include<iostream>
#include<stdio.h>
#include<algorithm>

using namespace std;
void result();

int main(){
   int T;
   scanf("%d", &T);
   for(int i=0;i<T;i++) 
      result();

return 0;

}

void result(){
   int N,L,H, temp;
   scanf("%d%d%d", &N,&L, &H);
   int arr[N];
   for(int i=0;i<N;i++){
	scanf("%d", &temp);
	arr[i] = temp;
   }
   int size = sizeof(arr)/sizeof(arr[0]);
   sort(arr, arr+size);
   
   int tempcount=0, count=0;
   for(int i=0;i<N-2;i++){
	for(int j=i+1;j<N-1;j++){
	   for(int k=j+1;k<N;k++){
		tempcount = arr[i]+arr[j]+arr[k];
		
		if(tempcount>H) break;
		else if(tempcount>= L && tempcount <= H) count++;		
	   }
	}
   }
printf("%d\n", count);
}
