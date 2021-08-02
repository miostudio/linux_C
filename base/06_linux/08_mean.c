#include<stdio.h>
int main(){
	int sum, n;
	//printf("please input sum,n:");
	scanf("%d,%d", &sum, &n);
	if(n<=0){
		fprintf(stderr, "Error: N>0\n");
		return 1;
	}
	float mean=sum/n;
	//printf("sum=%d, n=%d, mean=%f\n", sum, n, mean);
	printf("%f", mean);
	return 0;
}
