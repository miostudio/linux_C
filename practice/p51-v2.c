//结构体.ele, 结构体指针->ele
#include<stdio.h>
#include<string.h>
struct Student{
	int id;
	char name[10];
	char gender;
};

void input(struct Student *s, int id, char name[], char gender){
	s->id=id;
	strcpy(s->name, name);
	s->gender=gender;
}

void output(struct Student *s){
	printf("Student info: \n id:%d,\t name:%s\t gender:%c\n", s->id, s->name, s->gender);
}

int main(){
	struct Student stus[5];
	printf("请输入一个学生的信息，按回车结束，类似 1 Tom M:");
	
	int i, id;
	char name[10];
	char gender;
	
	for(i=0; i<5; i++){
		scanf("%d %s %c", &id, name, &gender);
		input(&stus[i], id, name, gender);
	}
	for(i=0; i<5; i++){
		output(&stus[i]);
	}
	return 0;
}

