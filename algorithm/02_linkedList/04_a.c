#include<stdio.h>

int len=10;
//len=20; //赋值报错，只能在函数中赋值？


int arr[] = {1,2,3};
//arr[1]=101;


int main(){
	printf("hello, %d\n", len);
	
	for(int i=0; i< sizeof(arr)/ sizeof(int); i++){
		printf("arr[%d]=%d\n", i, arr[i]);
	}
	
	return 0;
}