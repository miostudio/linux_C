#include<stdio.h>

//去掉最小的数(其后的值前移)，并返回该值
int rmLeastIndex(int arr[], int *len){
	int i, index=0;
	for(i=0; i<*len; i++){
		if(arr[index] > arr[i]){
			index=i;
		}
	}
	//最小值
	int num=arr[index];
	for(i=index; i<*len-1; i++){
		arr[i]=arr[i+1];
	}
	(*len)--;
	return num;
}
//输出数组
void showArr(int arr[], int len){
	for(int i=0; i<len; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

int main(){
	int arr[]={5, 3, 8, 2, 9};
	int j, len=sizeof(arr)/sizeof(int), cost, totalCost=0;
	int val[2];
	
	while(len>1){
		cost=0;
		for(j=0; j<2; j++){
			val[j]= rmLeastIndex(arr, &len);
			cost += val[j];
			//showArr(arr, len);
		}

		arr[len]=cost;
		len++;
		//showArr(arr, len);
		
		totalCost+=cost;
		printf("rm %d, %d, cost=%d, totalCost=%d, len=%d\n", val[0], val[1], cost, totalCost, len);
	}
	printf("=>total cost=%d\n", totalCost);
	return 0;
}
