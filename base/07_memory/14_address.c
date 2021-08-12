#include<stdio.h>
#include<stdlib.h>
int a = 0; //全局初始化区
char *p1; //全局未初始化区
int main() {
	int b; //栈
	char s1[] = "abc"; //栈
	char *p2; //栈
	char *p3 = "123456";  //123456\0在常量区，p3在栈上。
	static int c =0;   //全局（静态）初始化区
	p1 = (char *)malloc(10);  //堆
	p2 = (char *)malloc(20);  //堆
	
	printf("%p(a)\n", &a);
	printf("%p(b)\n", &b);
	printf("%p(c)\n", &c);
	
	printf("%p(p1) -> %p\n", &p1, p1);
	printf("%p(p2) -> %p\n", &p2, p2);
	printf("%p(p3) -> %p\n", &p3, p3);
	printf("%p(s1) -> %p %p %p\n", &s1, s1, &s1[0], &s1[1]);
	return 0;
}
