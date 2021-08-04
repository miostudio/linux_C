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
	int a=1, b=100, count=0;
	int n=getRand(a, b);
	int guess=-1, flag=0;
	
	printf("系统已经生成一个[0, 100]的随机数，请猜出该数字:\n");
	while(0==flag){
		scanf("%d", &guess);
		if(guess<0 || guess>100){
			printf("输入错误，输入范围[0, 100]");
			continue;
		}
		//如果对了
		if(guess == n){
			printf("猜对了！恭喜\n");
			break;
		}else if(guess<n){
			printf("小了，再猜\n");
			continue;
		}else if(guess>n){
			printf("大了，再猜\n");
		}
		
		if(count++>50){
			printf("尝试次数过多，已退出\n");
			break;
		}
	
	}
	return 0;
}
