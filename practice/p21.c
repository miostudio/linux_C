#include<stdio.h>
static int arr[30]={1, 1,2,3,5,8,13, 21};

int fib(int n){
	if( 0 != arr[n] ){
		return arr[n];
	}
	return fib(n-1)+fib(n-2);
}

int main(){
	int i=0;
	for(i=5; i<23; i++){
		arr[i]=fib(i);
	}
	
	float sum=0;
	for(i=1; i<=20; i++){
		sum+= (float)arr[i+1]/(float)arr[i];
		printf("i=%d, %d/%d,  sum=%f\n", i, arr[i+1], arr[i], sum);
	}
	return 0;
}
