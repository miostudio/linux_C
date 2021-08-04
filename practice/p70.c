#include<stdio.h>
int main(){
	FILE *fp;
	fp=fopen("backup/01.txt", "w");
	if( fp==NULL ){
        printf("error: cannot open file!\n");
        return -1;
    }
	//保存
	char ch;
	printf("请输入想保存的文件，#结束\n");
	while( (ch=getchar())!= '#'){
		fputc(ch, fp);
	}
	fclose(fp);
	return 0;
}
