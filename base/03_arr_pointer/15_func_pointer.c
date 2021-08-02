#include<stdio.h>
void bubbleSort(int arr[], int n){
	int i,j, tmp;
	for(i=0; i<n; i++){
		for(j=1; j<n; j++){
			if(arr[i]<arr[j]){
				tmp=arr[j];
				arr[j]=arr[i];
				arr[i]=tmp;
			}
		}
	}
}

int main(){
	int arr[]={0, -1,20,-300,4000, -30}, N=sizeof(arr)/sizeof(int);
	void (*p)(int arr[], int N)=&bubbleSort;
	(*p)(arr, N);
	for(int i=0; i<N; i++){
		printf("%d ", arr[i]);
	}
	printf("\n");
}

