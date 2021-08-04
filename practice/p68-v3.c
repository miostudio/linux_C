#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int getRand(int a, int b){
	srand((unsigned)time(NULL)); //1.随机数种子
	//int n=rand(); //2.随机数
	
	//3.生成一定范围内的随机数
	int n= rand() % b+a;
	return n;
}

int main(){
	int a=1, b=100;
	int n=getRand(a, b);
	printf("n=%d\n", n);
	
	return 0;
}
