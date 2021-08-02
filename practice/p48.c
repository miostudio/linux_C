#include<stdio.h>
void printArr(int arr[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int N=10, i;
	int arr[]={10,-26,38,-41,53,-64,-75,80,-98,106};
	int arr2[10];
	int shift=0;
	printf("请输入后移量: ");
	scanf("%d", &shift);
	
	// 偏移位置
	for(i=0; i<N; i++){		
		arr2[i]=arr[ (N+i-shift) %N ];
	}
	
	printArr(arr, N);
	printArr(arr2, N);	
}
