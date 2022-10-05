#include<stdio.h>
#include<stdlib.h>

#include "func.c"

//输出链表，更精美的格式
void print2(LinkList* h){
	if(h->next == NULL){
		printf("empty linked list\n");
	}else{
		h=h->next;
		while(h){
			if(h->next != NULL)
				printf("[%d, next:%3p]->", h->score, h->next );
			else
				printf("[%d, next:%3p]", h->score, h->next );
			h=h->next;
		}
		printf("\n");
	}
}


// 定义一个函数指针，灵活改变输出的指针
void (*pprintL)(LinkList*) = &print;


// 在尾部插入一个元素
void push_back(LinkList* h, int val){
	while(h->next != NULL){
		h = h->next;
	}
	h->next = (LinkList*) malloc(sizeof(LinkList));
	h->next->score = val;
}


// 在首位插入元素
void push_front(LinkList* h, int val){
	LinkList* node = (LinkList*) malloc(sizeof(LinkList));
	node->score = val;
	node->next = h->next;
	
	h->next = node;
}


//在第n个元素后添加新元素val
void insert(LinkList* h, int pos, int val){
	int i=0;
	//LinkList *pre;
	
	// 找到要插入的位置
	while(h->next != NULL){
		if(i == pos){
			break;
		}
		h = h->next;
		i++; //计数器，表示位置
	}

	// 新建节点
	LinkList* node = (LinkList*) malloc(sizeof(LinkList));
	node->score = val;

	// 插入新元素
	if(i == pos){
		node->next = h->next;
		h->next = node;
	}else if(i < pos){
		free(node); //如果没有插入值，额释放新建元素的内存
		printf("链表总长度为%d，没有第%d个元素，插入失败\n", i, pos);
	}
}


//链表长度
int length(LinkList* h){
	int i=0;
	while(h->next != NULL){
		h = h->next;
		i++;
	}
	return i;
}


int main(){
	pprintL = &print2; //可以对该指针重新赋值
	
	int N = 4;
	int nth, val;
	LinkList* h=create(N);//创建链表
	pprintL(h);//输出链表
	printf("\n");

	// 尾插
	printf("1>> push back val\n");
	scanf("%d", &val);
	push_back(h, val);
	pprintL(h);//输出链表
	printf("length of linked array: %d\n", length(h) );
	printf("\n");
	
	// 首插
	printf("2>> push front val\n");
	scanf("%d", &val);
	push_front(h, val);
	pprintL(h);//输出链表
	printf("length of linked array: %d\n", length(h) );
	printf("\n");
	
	
	//随意位置插入
	printf("3>>输入要插入元素的位置和值, nth val\n");
	scanf("%d %d", &nth, &val);
	insert(h, nth, val);
	pprintL(h);
	printf("length of linked array: %d\n", length(h) );
	printf("\n");
	
	return 0;
}
