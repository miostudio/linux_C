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
	if( (fp=fopen("backup/test4.data", "rb")) == NULL ){
		printf("open file failed!\n");
		exit(1);
	}
	//读取存储的学生信息
	printf("output file content:\n");
	printf("学号            姓名            年龄\n");
	//从fp指向的二进制文件读取数据,每次读取大小为size个字节的数据  
    //执行 1 次；最后将这些数据保存到结构体变量的地址内存中  
    //返回值正常时是读取的数据库个数(count)的值,否则返回0(错误或文件尾)
	while( fread(&stu, sizeof(stu), 1, fp) == 1 ){
		printf("%-15d%-15s%-15d\n", stu.id, stu.name, stu.age);
	}
	fclose(fp);
	return 0;
}
