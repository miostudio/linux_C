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
