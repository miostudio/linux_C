#include<stdio.h>
int main(){
	int i=10, sum=1;
	for(i=10; i>0; i--){
		printf("第 %d 天，吃前剩下 %d 个\n", i, sum);
		sum=(sum+1)*2;
	}
	return 0;
}
