#include<stdio.h>

void showStar(int n){
	int i;
	for(i=0; i<n; i++){
		printf("*");
	}
	printf("\n");
}

int main(){
	int i, arr[]={5,10,20};
	for(i=0; i<3; i++){
		showStar(arr[i]);
	}
	return 0;
}
