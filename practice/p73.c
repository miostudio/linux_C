#include<stdio.h>
#include<stdlib.h>
const int N=3;
struct Student{
	int id;
	char name[10];
	int Chinese;
	int Math;
	int English;
	float avg;
};

float avg(struct Student *ptr){
	return (float)(ptr->Chinese + ptr->Math + ptr->English)/N;
}

int main(){
	struct Student stus[N];
	int i;
	for(i=0; i<N; i++){
		printf("请输入学生 %d 的信息: id 姓名 成绩1 成绩2 成绩3\n", i);
		scanf("%d %s %d %d %d", &stus[i].id, stus[i].name, &stus[i].Chinese, &stus[i].Math, &stus[i].English);
		//计算平均分1
		stus[i].avg = avg(&stus[i]);
	}
		
	//保存到文件
	FILE *fp=fopen("backup/03.txt", "w");
	if( fp==NULL ){
		printf("Error: cannot open file!\n");
		exit(0);
	}
	
	for(i=0; i<N; i++){
		fprintf(fp, "%d %s %d %d %d %f\n", stus[i].id, stus[i].name, stus[i].Chinese, stus[i].Math, stus[i].English, stus[i].avg);
	}
	fclose(fp);
	return 0;
}
