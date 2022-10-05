#include<stdio.h>
#include<stdlib.h>

#include "func.c"

//把等于某个值的节点都删除
void delete(LinkList *h, int val){
	LinkList *pre;
	int flag=0;
	while(h->next!=NULL){
		pre=h;
		h=h->next;
		if(h->score==val){
			flag+=1;
			pre->next = h->next;
			free(h); //释放该节点内存
			h=pre;
		}
	}
	
	if(!flag){
		printf("没有可删除的元素。\n");
	}else{
		printf("删除了%d个元素\n", flag);
	}
}

// 1 1 4 1, del 1


int main(){
        int N=4;
        LinkList* h=create(N);//创建链表
        print(h);//输出链表
        
        printf("输入要删除元素的值\n");
	int del;
	scanf("%d", &del);

        delete(h, del);
        print(h);
        return 0;
}
