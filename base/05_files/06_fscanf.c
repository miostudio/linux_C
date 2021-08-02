#include<stdio.h>
#include<stdlib.h>
int main(){
	//char msg[33];
	char msg[6][10];
	int day;
	FILE *fp=fopen("backup/test3.txt", "r");
	if( fp == NULL ){
		printf("open file failed!\n");
		exit(1);
	}
	//fscanf(fp, "msg: %s; day: %d\n", msg, &day); //结果不对，感觉遇到空格就停了
	fscanf(fp, "msg: %s %s %s %s %s %s day: %d\n", 
		msg[0],msg[1],msg[2],msg[3],msg[4],msg[5], &day);
	fclose(fp);
	printf("reading from file with fscanf() finished!\n");

	for(int i=0; i<6; i++){
		printf("read %d: |%s|\n", i, msg[i]);
	}
	printf("read: day=|%d|\n", day);
	return 0;
}

