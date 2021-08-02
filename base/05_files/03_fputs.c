#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char str[]="通过fputs方法写入文件\n";
	FILE *fp = fopen("backup/test2.txt","w");
	if(fp==NULL){
		printf("open file failed!\n");
		exit(1);
	}
	fputs(str, fp);
	fclose(fp);
	printf("写入长度%ld\n", strlen(str));
	return 0;
}
