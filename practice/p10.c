#include<stdio.h>
int cubic(int a){
	return a*a*a;
}
int main(){
	int i;
	for(i=100; i<=999; i++){
		int a,b,c;
		//a=i/100; //百位
		//b=i/10 - 10*a; //十位
		//c=i-10*b-100*a; //各位
		
		a=i%10;
	        b=i/10%10;
        	c=i/100%10;

		if( i == cubic(a)+cubic(b)+cubic(c) ){
			printf("%d\t", i);
		}
	}
	printf("\n");
}
