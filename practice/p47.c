#include<stdio.h>
void swap(int *x, int *y){
	int tmp=*x;
	*x=*y;
	*y=tmp;
}

void printArr(int arr[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int i,j, n, arr[20];
	printf("设定数组长度(n<20):");
	scanf("%d", &n);
	
	printf("输入 %d 个数组元素\n", n);	
	for(i=0; i<n; i++){
		scanf("%d", &arr[i]);
	}
	
	int iMax=0, iMin=0;
	for(i=1; i<n; i++){
		if( arr[iMax]<arr[i] ){
			iMax=i;
		}
		if( arr[iMin]>arr[i] ){
			iMin=i;
		}
	}
	
	//交换
	swap(&arr[iMax], &arr[0]);
	swap(&arr[iMin], &arr[n-1]);

	printArr(arr, n);
}
