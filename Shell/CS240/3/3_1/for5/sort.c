#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc,char* argv[]){
	int* data;
	int size = argc-1;
	int i = 0, j=0;
	//printf("%d \n",size); 
	//printf("%d \n", atoi(argv[1]));
	data = malloc(size*sizeof(int));
	for(i=0; i<size; i++ ){
		data[i]= atoi(argv[i+1]);
	}
        for(i=0; i<size-1; i++){
		for(j=i+1; j<size; j++) {
			if(data[i] > data[j]){
				data[i] = data[i] + data[j];
				data[j] = data[i] - data[j];
				data[i] = data[i] - data[j];
			}
		}
	}
	for(i=0; i<size; i++){
		printf("%d ",data[i]);
	}
	printf("\n");
	free(data);
	return 0;
}
