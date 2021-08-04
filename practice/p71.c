#include<stdio.h>
int main(){
	FILE *fp;
	fp=fopen("backup/02.txt", "w");
	if( fp==NULL ){
        printf("error: cannot open file!\n");
        return -1;
    }
	
	printf("A(%d), a(%d)\n", 'A', 'a'); //A(65), a(97)
	printf("Z(%d), z(%d)\n", 'Z', 'z'); //Z(90), z(122)
	
	//保存
	char ch;
	printf("请输入想保存的文件，以!结束\n");
	while( (ch=getchar())!= '!'){
		//小写变大写
		if( ch>=97 && ch<=122 )
			ch=ch-32;		
		fputc(ch, fp);
	}

	fclose(fp);
	return 0;
}
