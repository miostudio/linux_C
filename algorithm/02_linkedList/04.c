#include<stdio.h>
#include<stdlib.h>

#include "func.c"

//在第n个元素后添加新元素val
void insert(LinkList* h, int n, int val){
	int i=0;
	LinkList *pre;
	LinkList* node=(LinkList*)malloc(sizeof(LinkList));
	node->score=val;
	while(h->next != NULL){
		if(i==n){
			break;
		}
		h=h->next;
		i++;
	}
	//如果插入位置在最后一个位置后面，则特殊考虑
	if(i==n){
		node->next=h->next; //null
		h->next=node;
	}else if(i<n){
		free(node);  //如果没有插入值，额释放新建元素的内存
		printf("链表总长度为%d，没有第%d个元素，插入失败\n", i, n);
	}
}

//链表长度
int length(LinkList* h){
	int i=0;
	while(h->next != NULL){
		h=h->next;
		i++;
	}
	return i;
}

int main(){
	int N=4;
	LinkList* h=create(N);//创建链表
	print(h);//输出链表
	
	printf("输入要插入元素的位置和值, nth val\n");
	int nth, val;
	scanf("%d %d", &nth, &val);
	insert(h, nth, val);
	
	print(h);
	printf("length of linked array: %d\n", length(h) );
	return 0;
}

