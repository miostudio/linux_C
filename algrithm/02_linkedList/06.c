#include<stdio.h>
#include<stdlib.h>

#include "func.c"

//反序
void reverse(LinkList* h){
	LinkList *pre, *cur;
	
	//销毁head元素
	cur=h;
	h=h->next;
	cur->next = NULL;
	
	while(h->next != NULL){
		pre=h;
		h=h->next;

		//翻转指针
		pre->next = cur->next;
		
		//备份上一个节点坐标
		cur->next = pre;
	}
	//翻转最后一个指针
	h->next = cur->next;
	cur->next=h;
	h=cur;
}


int main(){
	int N=4;
	LinkList* h=create(N);//创建链表
	print(h);//输出链表
	
	printf("反序后\n");
	reverse(h);
	print(h);
	return 0;
}

