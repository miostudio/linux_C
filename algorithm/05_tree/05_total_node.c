#include<stdio.h>
#include<stdlib.h>

typedef struct btnode{
	char data;
	struct btnode* lchild;
	struct btnode* rchild;
} BtNode;

// 先序遍历 二叉树
void prior_order(BtNode *tree){
	if(tree){ //空节点直接跳过
		printf("%c >", tree->data);
		prior_order( tree->lchild );
		prior_order( tree->rchild );
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

//二叉树的创建可以使用递归方法
void create(BtNode **node){
	printf("逐个输入字符，递归生成二叉树\n");
	char ch;
	scanf("%c", &ch);
	getchar(); //吃掉回车键
	
	if(ch=='/')
		return;
	*node = ( BtNode* )malloc( sizeof(BtNode) );
	
	(*node)->data=ch;
	printf("data: %c\n", (*node)->data );
	
	(*node)->lchild=NULL;
	(*node)->rchild=NULL;
	
	create( &(*node)->lchild);
	create( &(*node)->rchild);
}

void deltree(BtNode * tree) {
    if(tree) {
        deltree(tree->lchild);
        deltree(tree->rchild);
        free(tree);
    }
}

//递归求节点总数
void total_node(BtNode *tree, int *count){
	if(tree){
		*count+=1;
		total_node( tree->lchild, count);
		total_node( tree->rchild, count);
	}
}

int main(){
	BtNode *p; 
	create(&p);

	prior_order(p);
	printf("\n");

	in_order(p);
	printf("\n");

	post_order(p);
	printf("\n");

int N=0;
total_node(p, &N);
printf("该二叉树中总节点数: %d\n", N);
	
	deltree(p);
	return 0;
}

