#include<stdio.h>
#include<stdlib.h>

#include "func.c"

int length(LinkList* h){
	int i=0;
	while(h->next != NULL){
		i++;
		h=h->next;
	}
	return i;
}

void destroy(LinkList* h){
	if(h->next == NULL){
		printf("empty list\n");
	}else{
		// 从头元素一个一个删
		while(h->next != NULL){
			LinkList* cur = h->next;
			h->next = cur->next;
			free(cur);
		}
	}
}

int main(){
	int N=4;
	LinkList* h=create(N);//创建链表
	print(h);//输出链表
	printf("\n");
	
	printf(">> length:%d\n", length(h));
	
	//销毁后
	destroy(h);
	printf(">> length:%d\n", length(h));
	
	print(h);
	free(h); //头元素也删除
	return 0;
}
