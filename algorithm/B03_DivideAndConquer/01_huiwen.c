#include<stdio.h>
int isPal(char arr[], int start, int end){
	if( end-start <=1){
		return 1;
	}
	
	return arr[start]==arr[end] && isPal(arr, start+1, end-1);
}

int main(){
	char arr[]="doggod";
	int len=sizeof(arr)/sizeof(char) -1;
	int rs = isPal(arr, 0, len-1);
	printf("rs=%d\n", rs);
	return 0;
}
