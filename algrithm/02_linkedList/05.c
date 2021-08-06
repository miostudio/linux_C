#include<stdio.h>
#include<stdlib.h>

#include "func.c"

// 冒泡法排序
void sort(LinkList *h){
	LinkList *h2;
	while(h->next != NULL){
		h=h->next;
		h2=h;
		while(h2->next != NULL){
			h2=h2->next;
			if(h->score > h2->score){
				int tmp=h->score;
				h->score=h2->score;
				h2->score=tmp;
			}
		}
	}
}

int main(){
        int N=4;
        LinkList* h=create(N);//创建链表
        print(h);//输出链表

	printf("排序后\n");		
        sort(h);  //排序
        print(h);
        return 0;
}
