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

void bubbleSort(int arr[], int n){
	int i=0, j=0;
	for(i=0; i<n-1; i++){
		for(j=0; j<n-1; j++){
			if(arr[j]>arr[j+1]){
				int tmp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=tmp;
			}
		}
	}
}

int main(){
	int N=10, arr[]={0,1,-20,30,-40,500,-60,70,-800,90};
	printArr(arr, N);
	bubbleSort(arr, N);
	printArr(arr, N);
}
