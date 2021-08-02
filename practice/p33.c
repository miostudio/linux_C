#include<stdio.h>
int main(){
	int arr[3][3]={
		{1, 20, 30}, 
		{2, 50, -90}, 
		{3, 30, 60}
		};
	int i,j, N=3, sum=0;
	for(i=0; i<N; i++){
		for(j=0; j<N; j++){
			if(i==j){
				sum+=arr[i][j];
			}
		}
	}
	printf("sum of diag = %d\n", sum);
	return 0;
}
