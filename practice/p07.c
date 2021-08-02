#include<stdio.h>
static long arr[41]={0, 1,1,2};

long fib(int n){
	if(arr[n]!=0){
		return arr[n];
	}
	return fib(n-1)+fib(n-2);
}

int main(){
	int i=0;
	for(i=1; i<=40; i++){
		arr[i]=fib(i);
		printf("arr[%d]=%ld\n", i, arr[i]);
	}
	return 0;
}
