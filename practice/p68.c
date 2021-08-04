#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int a=1, b=100;
	srand((unsigned)time(NULL));

	//int n=rand();
	//生成一定范围内的随机数
	int n= rand() % 10;

	printf("n=%d\n", n);
	return 0;
}
