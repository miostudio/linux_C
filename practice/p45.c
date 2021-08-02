#include<stdio.h>
int main(){
	int a=123456789;
	int b=a%10000000;
	printf("%d 取右边7位为 %d\n", a,b);
	
	//整除1000
	int c=b/1000;
	printf("%d 取左边3位为 %d\n", b, c);
	return 0;
}
