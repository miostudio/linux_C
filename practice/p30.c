#include<stdio.h>
#include<math.h>
int isPrimer(int n){
	int i;
	for(i=2; i<= sqrt(1.0*n); i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int isPrimer2(int n){
	int i;
	for(i=2; i<n; i++){
		if(n%i==0){
			return 0;
		}
	}
	return 1;
}

int main(){
	int i, j=1;
	for(i=2; i<1000; i++){
		if( 1== isPrimer(i) ){
			printf("%3d ", i);
			if(j++%20 ==0){
				printf("\n");
			}
		}
	}
	printf("\n");
	return 0;
}
