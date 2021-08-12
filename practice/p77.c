#include<stdio.h>
int main(){
	int arr[]={99, 100, 1,-2,3,-4,5,-6,7,8};
	int N, i;
	int max=arr[0], second=arr[0];
	N=sizeof(arr)/sizeof(int);
	for(i=0; i<N; i++){
		if( arr[i]>max )
			max=arr[i];
	}
	//第二次
	for(i=0; i<N; i++){
		if(second==max)
			second=arr[i];
		if( arr[i]>second && arr[i]<max ){
			second=arr[i];
		}
	}
	printf("次最大值是: %d\n", second);
	return 0;
}
