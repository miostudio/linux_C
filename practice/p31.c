#include<stdio.h>

void printArr(char arr[], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%c", arr[i]);
	}
	printf("\n");
}

void reverse(char arr[], int n){
	int i, j, tmp;
	for(i=0; i<n/2; i++){
		j=n-1-i;
		tmp=arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
	}
}

int main(){
	char arrC[]="www.abcd.com:8000";
	int len=sizeof(arrC) / sizeof(char);
	printArr(arrC, len);
	reverse(arrC, len);
	printArr(arrC, len);
	return 0;
}
