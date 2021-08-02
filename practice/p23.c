#include<stdio.h>
long double fact(int x){
	if(x<=1)
		return 1;
	else
		return x*fact(x-1);
}

int main(){
	int n=5;
	for(int i=0; i<=n; i++){
		long double result=fact(i);
		printf("%d!=%5.0Lf\n", i, result);
	}
	return 0;
}
