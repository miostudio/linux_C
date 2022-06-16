#include<stdio.h>
int BinarySearch(int arr[], int len, int target){
	int low=0, high=len-1, mid;
	while(low <= high){
		mid=(low+high)/2;
		
		if(target == arr[mid]){
			return mid;
		}else if(target < arr[mid]){
			high=mid-1;
		}else{
			low=mid+1;
		}
	}
	return -1;
}

int main(){
	int arr[]={1,3,4,6,8,10};
	
	int num=4, index, n=sizeof(arr)/sizeof(int);
	index=BinarySearch(arr, n, num);
	printf("index = %d\n", index);
	return 0;
}
