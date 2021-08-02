#include<stdio.h>
#include "00.c"

void insertion_sort(int arr[], int len){
    int i,j,temp;
    for (i=1;i<len;i++){
            temp = arr[i];
            for (j=i;j>0 && arr[j-1]>temp;j--){
                    arr[j] = arr[j-1];
			}
            arr[j] = temp;
    }
}

int main(){
	int N=10, arr[]={0,1,-20,30,-40,500,-60,70,-800,90};
	printArr(arr, N);
	insertion_sort(arr, N);
	//selSort(arr, N);
	printArr(arr, N);
}
