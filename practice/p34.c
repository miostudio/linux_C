
#include<stdio.h>
int getPos(int arr[], int N, int num){
	//二分法找到前一个元素的位置
	int low=0, high=N-1, mid=(low+high)/2, oldMid=-1;
	while(low<high){
		if( num > arr[mid]){
			low=mid;
			mid=(low+high)/2;
		}else if(num <arr[mid]){
			high=mid;
			mid=(low+high)/2;
		}else{
			return mid;
		}
		//查看是否调整过位置
		if(oldMid==mid){
			return low;
		}else{
			oldMid=mid;
		}
	}
}

int main(){
	int arr[]={-81, -66, -42, -20, 0, 17, 35, 59, 78, 92};
	int N=10, num, i;
	printf("please input a numer, [-100, 100]:");
	scanf("%d", &num);
	
	// 获取前一个元素的位置
	int pos=getPos(arr, N, num);
	for(i=0; i<N; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
	//插入新元素
	for(i=0; i<N; i++){
		printf("%d ", arr[i]);
		if(i==pos){
			printf("%d ", num);
		}
	}
	printf("\n");
	return 0;
}
