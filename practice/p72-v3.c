#include<stdio.h>
#include<stdlib.h>

//输出字符串数组
void showArr(char arr[50][10], int n){
	int i;
	for(i=0; i<n; i++){
		printf("%s ", arr[i]);
	}
	printf("\n");
}

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
			n++;
			i=0;
		}else
			*(strA[n] + i++)=str;
	}
	*(strA[n] + i++)='\0';
	n++;
	i=0;
	fclose(fp);
	showArr(strA, n); //输出字符串
	
	
	//读文件B
	fp=fopen("backup/B.txt", "r");
	
	while( (str=fgetc(fp))!= '\n' ){ //EOF
		if(str==' '){
			*(strA[n] + i++)='\0';
			n++;
			i=0;
		}else
			*(strA[n] + i++)=str;
	}
	*(strA[n] + i++)='\0';
	n++;
	fclose(fp);
	showArr(strA, n); //输出字符串
	
	return 0;
}
