#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
	char *str;
	//最初的内存分配
	str= (char *) malloc(6);
	strcpy(str, "hello");
	printf("string=%s, address=%p\n", str, str);
	
	// 重新分配内存，更大空间
	str=(char *) realloc(str, 25);
	strcat(str, " world!");
	printf("string=%s, address=%p\n", str, str);
	
	//释放内存
	free(str);
	
	return 0;
}

