#include<stdio.h>
int main(){
	char s1[] = "aaaaaaaaaaaaaaa"; 
	char *s2 = "bbbbbbbbbbbbbbbbb"; 
	printf("aaaaaaaaaaa是在运行时刻赋值的；放在栈中\n");
	printf("而bbbbbbbbbbb是在编译时就确定的；放在堆中\n");
	printf("%p -> %p: %s\n", &s1, s1, s1);
	printf("%p -> %p: %s\n", &s2, s2, s2);
	return 0;
}
