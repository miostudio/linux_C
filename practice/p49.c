#include<stdio.h>
#include<stdlib.h>

void printArr(int *arr, int n){
	int i;
	for(i=0; i<n; i++){
		printf("%d ", *(arr+i));
	}
	printf("\n");
}

// 删除第j个元素，就是第j个元素被后一个元素覆盖
void delArr(int *arr, int n, int j){
	int i;
	for(i=j; i<n; i++){
		*(arr+i)=*(arr+i+1);
	}	
}

int main(){
	int counter=0, n, remain;
	printf("input the number of total people:");
	scanf("%d", &n);
	
	//输入总人数 n
	if(0==n)
		return 1;
	if(n<1){
		printf("Error: must >1\n");
		return 1;
	}
	remain=n;
	//分配一块内存
	int i, *arr0, *arr=malloc( sizeof(int)*n);
	arr0=arr;
	//初始化
	for(i=0; i<n; i++){
		*(arr+i)=(i+1);
	}
	
	int j;
	while(remain>1){
		printf("==> remain=%d (first element counter=%d)\n", remain, counter+1);
		printArr(arr, remain); //剩余元素
		//报数，遇到3的倍数，则
		for(j=0; j<remain; j++){
			counter++;
			counter=counter%3;
			if(counter==0){
				printf("删除元素: %d\n", arr[j]);
				delArr(arr, remain, j); //删除数组arr的第j个元素，后面的前移
				j--;
				remain--;
			}
			
		}
	}
	printf("剩下的元素是: %d\n", arr[0]);
	return 0;
}
