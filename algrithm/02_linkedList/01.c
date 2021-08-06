#include<stdio.h>
#include<stdlib.h>

#include "func.c"

int main(){
	int N=3;
	LinkList* h=create(N);//创建链表
	print(h);//输出链表
	return 0;
}

