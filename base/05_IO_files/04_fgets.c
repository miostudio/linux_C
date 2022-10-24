#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main(){
	char str[50];
	FILE *fp = fopen("backup/test2.txt","r");
	if(fp==NULL){
		printf("open file failed!\n");
		exit(1);
	}
	/*fgets(str, 20, fp);
	printf("len=%ld: %s\n", strlen(str), str);*/
	//这里写3是因为,汉字是占2个字节的  
	int n=0;
	while( fgets(str, 2, fp)!= NULL ){
		printf("%s", str);
		n+=2;
	}
	printf("reading: len=%d\n", n);
	fclose(fp);
	return 0;
}
