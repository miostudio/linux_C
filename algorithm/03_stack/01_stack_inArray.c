#include<stdio.h>
#include<stdlib.h>

int *createStack(int n){
	if(n<0){
		fprintf(stderr, "Stack must >=0\n");
		exit(-1);
	}
	int *p=(int *)malloc(sizeof(int)*n);
	return p;
}

// 压入元素
int push(int *stack, int n, int ele){
	stack[++n]=ele;
	return n;
}

//弹出元素
int pop(int *stack, int n){
	if(-1==n){
		printf("空栈\n");
		return -1;
	}
	int ele = stack[n];
	printf("弹出 %dth: %d\n",n, ele);
	return --n;
}

int main(){
	int len=100, nth=-1;
	int *stack=createStack(len);
	
	nth=push(stack, nth, 101);
	nth=push(stack, nth, 202);
	nth=push(stack, nth, 303);
	nth=pop(stack, nth);
	nth=pop(stack, nth);
	nth=pop(stack, nth);
	
	nth=pop(stack, nth);
	free(stack);
	return 0;
}
