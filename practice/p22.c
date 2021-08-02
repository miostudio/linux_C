#include<stdio.h>
int main(){
	int i;
	long double sum=0, item=1;
	for(i=1; i<=20; i++){
		item*=i;
		sum+=item;
		printf("%2d!=%20.0Lf, sum=%20.0Lf\n",i, item, sum);
	}
	//printf("sum=%20.0Lf\n", sum);
	return 0;
}
