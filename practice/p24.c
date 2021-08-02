#include<stdio.h>
int main(){
	char c[5];
	printf("请输入5个字符: ");
	for(int i=0; i<5; i++){
		c[i]=getchar();
	}
	for(int i=4; i>=0; i--){
		printf("%c", c[i]);
	}
	printf("\n");
	return 0;
}
