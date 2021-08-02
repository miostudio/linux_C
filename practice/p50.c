#include<stdio.h>
int main(){
	char c, *str;
	int n=0;
	printf("请输入字符串, 回车结束: ");
	while( (c=getchar()) != '\n' ){
		n++;
	}
	printf("length=%d\n", n);
	return 0;
}
