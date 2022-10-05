#include<stdio.h>
#include<stdlib.h>

#include "func.c"

// 比较法排序
void sort_Cmp(LinkList *h){
	LinkList *h2;
	int tmp;
	while(h->next != NULL){
		h=h->next;
		h2=h;
		while(h2->next != NULL){
			h2=h2->next;
			if(h->score > h2->score){
				tmp = h->score;
				h->score = h2->score;
				h2->score = tmp;
			}
		}
	}
}

int main(){
	int N=4;
	LinkList* h=create(N);//创建链表
	print(h);//输出链表

	sort_Cmp(h);  //排序
	printf("排序后\n");		
	print(h);
	return 0;
}
