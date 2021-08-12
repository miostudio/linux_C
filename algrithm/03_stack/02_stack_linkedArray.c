#include<stdio.h>
#include<stdlib.h>

typedef struct node{
	int ele;
	struct node *next;
} Stack;

//入栈
Stack *push(Stack *h, int ele){
	Stack *node=(Stack *)malloc(sizeof(Stack));
	node->ele=ele;
	node->next=h;
	//printf("压入元素 %d %p\n", ele, node);
	return node;
}

//出栈 
Stack *pop(Stack *h){
	if(h){
		Stack *pre=h;
		h=h->next;
		//printf("弹出: %d(%p ->%p)\t", pre->ele, pre, h);
		printf("弹出: %d\t", pre->ele);
		if(h){
			printf("栈顶元素 %d\n", h->ele);
		}else{
			printf("栈已空\n");
		}
		free(pre);
	}else{
		printf("空栈\n");
	}
	return h;
}



int main(){
	Stack *stack=NULL;
	//压入
	stack=push(stack, 100);
	stack=push(stack, 200);
	stack=push(stack, 300);
	//弹出
	stack=pop(stack);
	stack=pop(stack);
	stack=pop(stack);

	stack=pop(stack);
	return 0;
}
