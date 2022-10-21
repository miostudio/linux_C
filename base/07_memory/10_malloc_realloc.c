#include<stdio.h>
#include<string.h>
#include<stdlib.h>
	//void* realloc(void* memblock, size_t size)
int main(){
	char *str;

	//1. 最初的内存分配
	str= (char *) malloc(6);
	strcpy(str, "hello");
	printf("string=%p, address=%s\n", str, str);
	
	//2. 重新分配内存，更大空间
	//str=(char *) realloc(str, 15); //如果后面有空间，则首地址不变。
	str=(char *) realloc(str, 1500);//如果不得不另外开辟空间，则首地址变化。
	strcat(str, " world!");
	printf("string=%p, address=%s\n", str, str); //原来的字符串内容不变，或者拷贝过来
	
	//3. 释放内存
	free(str);

	//Part II 还可以像 malloc 一样使用:
	int len=10;
	int* p = (int*)realloc(NULL, len);
	p[0]=125;
	for(int i=0; i<5; i++){
		printf("%d ", p[i]);
	}
	printf("\n");
	free(p);
	
	return 0;
}

