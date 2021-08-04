//随机数 [0, 100]
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	int a=1, b=100, i;
	srand((unsigned)time(NULL)); //随机数种子
	//int n=rand(); //随机数
	
	//生成一定范围内的随机数
	//int n= rand() % 10; [0,9]
	for(i=0; i<100; i++){
		int n= rand() % 100+1; //[0,99]+1 => [1,100]
		printf("%d n=%d\n",i, n);
	}
	return 0;
}
