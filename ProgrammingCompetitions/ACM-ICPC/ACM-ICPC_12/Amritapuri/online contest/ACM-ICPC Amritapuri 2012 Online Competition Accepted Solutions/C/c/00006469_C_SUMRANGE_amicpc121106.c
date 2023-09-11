#include<stdio.h>
#include<stdlib.h>
void mergesort( int* , int  );
void merge(int * , int  );

void mergesort( int* arr, int n ){

    if(n>1){
        
        mergesort(arr, n/2);
        mergesort(arr + n/2, n-n/2);
        merge(arr, n);
    }

}

void merge(int * arr, int n ){
   int i,j,k;
   int arr_1[1000];
   int arr_2[1000];
   
   for(i=0;i< n/2;i++){
        arr_1[i]=arr[i];
   
   } 
       
   for(j=0;i<n;j++,i++){
        arr_2[j]=arr[i];
   
   } 
   i=j=0; 
   k=0;
   while(k< n){
    if(i==n/2  && j!=n-n/2){
        arr[k] = arr_2[j];    
        j++;
    }
    
    else if(j== n-n/2 ){
        arr[k] = arr_1[i];
        i++;
    
    }
    
    
    else if(arr_1[i] <= arr_2[j]){
        arr[k] = arr_1[i];
        i++;     
    }
    
    else{
        arr[k] = arr_2[j];
        j++;
    
    }
    
    k++;
    
    }


}

int main(){
	int t,j,k,l;
	int i=0;	
	scanf("%d",&t);
	int n;
	int L,H,count;
	long temp;
	int* a = (int*)malloc(1000*sizeof(int));	
	for(i=0;i<t;i++){
		scanf("%d",&n);				
		scanf("%d",&L);				
		scanf("%d",&H);				
		for(j=0;j<n;j++){
			scanf("%d",&a[j]);				
		}
		mergesort(a,n);
		count=0;
		for(j=0;j<n-2;j++){
			if(a[j]>H) break;
			for(k=j+1;k<n-1;k++){
				if(a[j]+a[k]>H) break;
				for(l=k+1;l<n;l++){
					temp=a[j]+a[k]+a[l];					
					if(temp>H) break;					
					if(temp>= L)
					count++;
					
				}				
			}
		}
		printf("%d\n",count);
	}

	return 0;
}

