#include<stdio.h>
#include<stdlib.h>

//定义链表数据类型，数据，及指向下一个元素的指针
typedef struct student{
	int score;
	struct student *next;
} LinkList;


//创建链表
LinkList *create(int n){
	LinkList *head, *node, *end;
	head=(LinkList *)malloc(sizeof(LinkList)); //get address
	end=head; //if empty, head and end are the same
	
	printf("请输入需要创建的%d个链表的值，回车结束\n", n);
	for(int i=0; i<n; i++){
		node=(LinkList *)malloc(sizeof(LinkList));
		scanf("%d", &node->score);
		end->next=node;//point to the last end
		end=node; //the new end;
	}
	end->next=NULL; //the last node
	return head;
}

//输出链表 
void print(LinkList* h){
	while(h->next!=NULL){
		h=h->next;
		printf("value=%d, next:%p\n", h->score, h->next );
	}
}


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
			
			if(pre->next != NULL){
				h=pre->next; //当前节点指向下一个节点
			}else{
				h=pre; //下一节点为NULL则指向上一个节点
			}
		}
	}
	if(!flag){
		printf("没有可删除的元素。\n");
	}else{
		printf("删除了%d个元素\n", flag);
	}
}

//修改链表的值 
void sup(LinkList* h, int old, int new){
	while(h->next!=NULL){
		h=h->next;
		if(h->score == old){
			h->score = new;
		}
	}
}

//在第n个元素后添加新元素val
void insert(LinkList* h, int n, int val){
	int i=0;
	LinkList *pre;
	LinkList* node=(LinkList*)malloc(sizeof(LinkList));
	node->score=val;
	while(h->next != NULL){
		if(i==n){
			break;
		}
		h=h->next;
		i++;
	}
	//如果插入位置在最后一个位置后面，则特殊考虑
	if(i==n){
		node->next=h->next; //null
		h->next=node;
	}else if(i<n){
		free(node);  //如果没有插入值，额释放新建元素的内存
		printf("链表总长度为%d，没有第%d个元素，插入失败\n", i, n);
	}
}

//链表长度
int length(LinkList* h){
	int i=0;
	while(h->next != NULL){
		h=h->next;
		i++;
	}
	return i;
}

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


int getEle(LinkList* h, int n){
	int i=0;
	while(h->next != NULL){
		h=h->next;
		if(i==n){
			return h->score;
		}
		i++;
	}
	printf("Error: arr length(%d) < n(%d)\n", i, n);
	return -1;
}

int main(){
	int N=4;
	LinkList* h=create(N);//创建链表
	print(h);//输出链表
	
	printf("输出第几个元素?\n");
	int n;
	scanf("%d", &n);
	printf("the %dth ele is %d\n", n, getEle(h, n));
	return 0;
}

