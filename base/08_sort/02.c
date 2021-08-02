#include<stdio.h>
#include "00.c"

void selSort(int arr[], int n){
	int i,j;
	for(i=0; i<n-1; i++){
		int min=i; //最小值，默认为第一个元素
		for(j=i+1; j<n; j++){
			if(arr[j]<arr[min]){ //如果元素比第一个小，则记录其下标
				min=j;
			}
		}
		if(min != i){
			swap(&arr[min], &arr[i]);
		}
	}
}

int main(){
	int N=10, arr[]={0,1,-20,30,-40,500,-60,70,-800,90};
	printArr(arr, N);
	selSort(arr, N);
	printArr(arr, N);
}
