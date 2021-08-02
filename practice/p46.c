#include<stdio.h>
void printArr(int arr[], int N){
	int i;
	for(i=0; i<N; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int i, j, k, N=1;
	int arr[15]={1}, arr2[15];
	for(i=0; i<10; i++){
		printArr(arr, N);
		
		//生成新数组arr2，长度加1
		arr2[0]=1;
		for(j=1; j<N; j++){
			arr2[j] = arr[j-1] + arr[j];
		}
		//最后一位1
		arr2[N]=1;
		N++;
		
		//覆盖掉arr
		for(k=0; k<N; k++){
			arr[k]=arr2[k];
		}
	}
	return 0;
}
