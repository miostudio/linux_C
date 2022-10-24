#include<stdio.h>
#include<stdlib.h>
typedef struct{
	int id;
	char name[20];
	int age;
} STU;

int main(){
	STU stu;
	FILE *fp;
	char c;
	//内容是逐条追加的
	if( (fp=fopen("backup/test4.data","ab")) == NULL ){
		printf("open file failed!\n");
		exit(1);
	}
	//键盘录入学生信息
	while(1){
		printf("请输入学号:"); scanf("%d", &stu.id);
		printf("\n请输入姓名:"); scanf("%s", stu.name);
		printf("\n请输入年龄:"); scanf("%d", &stu.age);
		//参数依次是: 数据起始地址,每次写入的数据块的字节数,数据块的数目,文件指针
		fwrite(&stu, sizeof(stu), 1, fp );
		printf("\nContinue input?(Y/N)\n");
		getchar(); //这个是干啥的？
		c=getchar();
		if(c=='y' || c=='Y') continue;
		else break;
	}
	fclose(fp);
	return 0;
}
