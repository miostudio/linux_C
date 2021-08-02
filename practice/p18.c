#include<stdio.h>
int main(){
	int i=10, sum=1;
	printf("第 %d 天，吃前剩下 %d 个\n", i, sum);
	for(i=9; i>0; i--){
		sum=(sum+1)*2;
		printf("第 %d 天，吃前剩下 %d 个\n", i, sum);
	}
	return 0;
}
