#include<stdio.h>
int main(){
	int i,j;
	for(i=0; i<5; i++){
		for(j=0; j<5-i; j++){
			printf(" ");
		}
		for(j=0; j< (2*i-1) ; j++){
			printf("*");
		}
		printf("\n");
	}
	//δΈει¨ε
	for(i=3; i>=0; i--){
		for(j=0; j<5-i; j++){
			printf(" ");
		}
		for(j=0; j< (2*i-1) ; j++){
			printf("*");
		}
		printf("\n");
	}
}
