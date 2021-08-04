#include<stdio.h>
#include<stdlib.h>
int main(){
	FILE *fp=NULL;
	fp=fopen("backup/A.txt", "r");
	if( fp==NULL ){
		printf("error: cannot open file!\n");
		return -1;
	}
	
	//读文件A
	char strA[50][10], str;
	int i=0, n=0;
	while( (str=fgetc(fp))!= '\n' ){ //EOF
		if(str==' '){
			*(strA[n] + i++)='\0';
			i=0;
			n++;
		}else
			*(strA[n] + i++)=str;
	}
	*(strA[n] + i++)='\0';
	n++;
	
	//输出字符串
	for(i=0; i<n; i++){
		printf("%i ==> %s\n", i, strA[i]);
	}
	
	printf("\n");
	
	return 0;
}
