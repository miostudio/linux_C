#include<stdio.h>
int main(){
	int i,j;
	for(i=1; i<10; i++){
		for(j=1; j<=i; j++){
			printf("%d*%d=%-3d",j,i,i*j); /*-3d表示左对齐，占3位*/
			//printf("%d*%d=%d\t", j,i,i*j);
		}
		printf("\n");
	}
}
