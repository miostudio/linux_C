#include<stdio.h>
int BinarySearch(int arr[], int len, int target){
	int low=0, high=len-1, mid=(low+high)/2;
	int oldMid=mid;
	while(low < high){
		if(target > arr[mid]){
			low=mid;
			mid=(low+high)/2;
		}else if(target < arr[mid]){
			high=mid;
			mid=(low+high)/2;
		}else{
			return mid;
		}
		//看mid是否更新过，如果没有，则查找结束
		if(mid==oldMid){
			return -1;
		}else{
			oldMid=mid;
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
