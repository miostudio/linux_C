#include<stdio.h>
int BinarySearch3(int arr[], int len, int target){
	int low=0, high=len-1, mid;
	while(low <= high){
		mid=(low+high)/2;
		if(target == arr[mid]){
			return mid;
		//如果左边有序
		}else if(arr[0] < arr[mid]){
			if( arr[0]<=target && target<arr[mid] ){
				high=mid-1;
			}else{
				low=mid+1;
			}
		//如果右边有序
		}else{
			if( arr[mid]<target && target<arr[len-1] ){
				low=mid+1;
			}else{
				high=mid-1;
			}
			
		}
	}
	return -1;
}

int main(){
	int arr[]={4,5,6,7,0,1,2};
	int len=sizeof(arr)/sizeof(int);
	int num;
	num=0; printf("index if %d is %d\n", num,  BinarySearch3(arr, len, num) );
	num=3; printf("index if %d is %d\n", num,  BinarySearch3(arr, len, num) );
	return 0;
}

