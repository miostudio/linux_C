#include<stdio.h>
int BinarySearch2(int arr[], int low, int high, int target){
	if(low>high){
		return -1;
	}
	int mid;
	while(low <= high){
		mid=(low+high)/2;
		if(target == arr[mid]){
			return mid;
		}else if(target < arr[mid]){
			return BinarySearch2(arr, low, mid-1, target);
		}else{
			return BinarySearch2(arr, mid+1, high, target);
		}
	}
	return -1;
}

int main(){
	int arr[]={1,3,4,6,8,10};
	
	int num=4, index, n=sizeof(arr)/sizeof(int);
	index=BinarySearch2(arr, 0, n-1, num);
	printf("index if %d is %d\n", num,  index);
	return 0;
}
