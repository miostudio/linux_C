#include<stdio.h>

//选择法排序,选出最小的，放到最左边。
void selectSort(int arr[], int n){
	int i,j,index, tmp;
	for(i=0; i<n-1; i++){
		index=i; //最小值默认是第一个
		for(j=i; j<n; j++){
			if( arr[index]>arr[j] ){
				index=j;
			}
		}
		if(index!=i){
			tmp=arr[i];
			arr[i]=arr[index];
			arr[index]=tmp;
		}
	}
}

int main(){
	int n=10, i;
	int arr[]={0,17,-20,35,-42,59,-66,78,-81,92};
	selectSort(arr, 10);
	//打印结果
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	return 0;
}
