#include<stdio.h>
int main(){
	int a=3;
	int  b=2;
	int arr[3];
	arr[0]=1;
	arr[1]=20;
	arr[2]=300;
	int *p=&a, i;
	int N=10;
	for(i=0; i<N; i++){
		printf("*p=%d\n", *p);
		p++;
	}
	printf("== ==\n");
	p=&a;
	for(i=0; i<N; i++){
		printf("p[%d]=%d\n",i, p[i]);
	}
}

