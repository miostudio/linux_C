#include<stdio.h>
void reverse(int arr[], int n){
	int i,j;
	for(i=0; i<n/2; i++){
		j=n-1-i;
		int tmp=arr[i];
		arr[i]=arr[j];
		arr[j]=tmp;
	}
}

int main(){
	int arr[]={1,2,3,4,5};
	int n=5, i;
	reverse(arr, n);
	for(i=0; i<n; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}
