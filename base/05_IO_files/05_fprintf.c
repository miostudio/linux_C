#include<stdio.h>
#include<stdlib.h>
int main(){
	char msg[]="Henan suffered a flood last week.";
	int day=23;
	FILE *fp=fopen("backup/test3.txt", "w");
	if( fp == NULL ){
		printf("open file failed!\n");
		exit(1);
	}
	fprintf(fp, "msg: %s; day: %d\n", msg, day);
	fclose(fp);
	printf("writing to file with fprintf() finished!\n");
	return 0;
}

