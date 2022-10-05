#include<stdio.h>
#include<stdlib.h>

#include "func.c"

// 尾删：就是把倒数第二个节点的next指向null
void del_tail(LinkList* h){
	LinkList* cur;
	while(h->next != NULL){
		cur=h;
		h=h->next;
	}
	free(h);
	cur->next = NULL;
}


// 头删：头元素直接指向第二个元素
void del_head(LinkList* h){
	LinkList* cur;
	if(h->next == NULL){
		printf("empty link list\n");
	}else{
		LinkList* cur = h->next;
		h->next = cur->next;
		free(cur);
	}
}


// 删除指定位置的值
void del_pos(LinkList *h, int pos){
	LinkList *pre;
	int i=0, flag=0;
	while(h->next!=NULL){
		pre=h;
		h=h->next;
		if(i == pos){
			pre->next = h->next;
			free(h); //释放该节点内存
			flag +=1;
			break;
		}
		i += 1;
	}
	if(flag == 0){
		printf("删除失败\n");
	}
}


int main(){
	int N=4;
	LinkList* h=create(N);//创建链表
	print(h);//输出链表
	printf("\n");

	printf("1>> del tail element\n");
	del_tail(h);
	print(h);
	printf("\n");

	printf("2>> del head element\n");
	del_head(h);
	print(h);
	printf("\n");
	

	printf("输入要删除元素的下标\n");
	int pos;
	scanf("%d", &pos);
	del_pos(h, pos);
	print(h);
	return 0;
}
