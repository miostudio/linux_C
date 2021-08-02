#include<stdio.h>
int main(){
	int num;
	printf("输入一个整数:");
	scanf("%d", &num);
	
	int reverse=0, remainder;
	while(num>0){
		remainder=num%10;
		reverse = reverse*10 + remainder;
		num/=10;
	}
	printf("翻转后: %d\n", reverse);
	return 0;
}
