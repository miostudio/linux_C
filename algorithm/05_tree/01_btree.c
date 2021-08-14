#include<stdio.h>
#include<stdlib.h>
typedef struct btnode{
	char data;
	struct btnode* lchild;
	struct btnode* rchild;
} BtNode;

// 先序遍历 二叉树
void prior_order(BtNode *bt){
	if(bt){ //空节点直接跳过
		printf("%c >", bt->data);
		prior_order( bt->lchild );
		prior_order( bt->rchild );
	}
}

// 中序遍历 二叉树
void in_order(BtNode *tree){
	if(tree){ //空节点直接跳过
		in_order( tree->lchild );
		printf("%c >", tree->data);
		in_order( tree->rchild );
	}
}

// 后序遍历 二叉树
void post_order(BtNode *tree){
	if(tree){ //空节点直接跳过
		post_order( tree->lchild );
		post_order( tree->rchild );
		printf("%c >", tree->data);
	}
}

int main(){
	BtNode *p, *p1, *p2;

	p=( BtNode* )malloc( sizeof(BtNode) );
	p->data='A';

	p1=( BtNode* )malloc( sizeof(BtNode) );
	p1->data='B';
	p1->lchild=NULL;
	p1->rchild=NULL;

	p2=( BtNode* )malloc( sizeof(BtNode) );
	p2->data='c';
	p2->lchild=NULL;
	p2->rchild=NULL;

	p->lchild=p1;
	p->rchild=p2;

	prior_order(p); //遍历树的函数定义见下文
	printf("\n");
	
	in_order(p);
	printf("\n");

	post_order(p);
	printf("\n");

	free(p1);
	free(p2);
	free(p);
	return 0;
}

