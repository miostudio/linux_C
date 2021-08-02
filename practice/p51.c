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
	printf("Student info: \n id=%d\n name=%s\n gender=%c\n", s->id, s->name, s->gender);
}

int main(){
	struct Student stu1;
	input(&stu1, 1, "Jim", 'M');
	output(&stu1);
	return 0;
}
