
#include<stdio.h>
int main(){
	int x;
	printf("请输入分数： ");
	scanf("%d", &x);
	char grade=x>=90?'A':( x<60?'C':'B' );
	printf("score:%d, grade:%c\n", x, grade);
	return 0;
}
