#include<stdio.h>
#include "00.c"

void shell_sort(int arr[], int len) {
    int gap, i, j;
    int temp;
    for (gap = len >> 1; gap > 0; gap = gap >> 1){
        for (i = gap; i < len; i++) {
            temp = arr[i];
            for (j = i - gap; j >= 0 && arr[j] > temp; j -= gap){
                arr[j + gap] = arr[j];
			}
            arr[j + gap] = temp;
        }
	}
}

int main(){
	int N=10, arr[]={0,1,-20,30,-40,500,-60,70,-800,90};
	printArr(arr, N);
	shell_sort(arr, N);
	printArr(arr, N);
}
