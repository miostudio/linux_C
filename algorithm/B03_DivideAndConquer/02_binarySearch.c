#include<stdio.h>

int binarySearch(int arr[], int target, int low, int high){
	int mid=(low+high)/2;
	if( target == arr[mid]){
		return mid;
	}else if( target > arr[mid]){
		return binarySearch(arr, target, mid+1, high);
	}else{
		return binarySearch(arr, target, low, mid-1);
	}
}

int main(){
	int arr[]={1,3,5,7,9, 12, 200};
	int target=9, len=sizeof(arr)/sizeof(int);
	int index=binarySearch(arr, target, 0, len-1);
	printf("index of %d in arr is %d\n", target, index);
	return 0;
}
