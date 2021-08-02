#include<stdio.h>
void printArr(int arr[], int n){
	printf("[");
	for(int i=0; i<n; i++){
		if(i<n-1){
			printf("%d,", arr[i]);
		}else{
			printf("%d", arr[i]);
		}
	}
	printf("]\n");
}

void swap(int *a, int *b){
	int temp=*a;
	*a=*b;
	*b=temp;
}
