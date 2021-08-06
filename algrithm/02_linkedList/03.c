#include<stdio.h>
#include<stdlib.h>

#include "func.c"

//修改链表的值 
void sup(LinkList* h, int old, int new){
	while(h->next!=NULL){
		h=h->next;
		if(h->score == old){
			h->score = new;
		}
	}
}


int main(){
        int N=4;
        LinkList* h=create(N);//创建链表
        print(h);//输出链表
        
        printf("输入要替换元素的值, old new\n");
		int new, old;
		scanf("%d %d", &old, &new);
        sup(h, old, new);
		
        print(h);
        return 0;
}

