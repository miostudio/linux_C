#include<stdio.h>
#include <math.h>
int main(){
	int i, j, flag, n;
	for(i=101; i<200; i++){
		flag=1;
		for(j=2; j<i; j++){
			if(i % j ==0){
				flag=0;
				break;
			}
		}
		if(1==flag){
			printf("%d\t", i);
			n++;
			if(n%5==0) 
				printf("\n");
		}
	}
	printf("\n");
	return 0;
}
