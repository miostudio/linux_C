#include<stdio.h>
int main(){
   FILE *fp=NULL;
    fp=fopen("backup/A.txt", "r");
    if( fp==NULL ){
        printf("error: cannot open file!\n");
        return -1;
    }
	
	//读文件A
	char strA[50], str;
	int i=0;
	while( (str=fgetc(fp))!= '\n' ){
		strA[i++]=str;
		printf("%c", str);
	}
	printf("\n");
	
	return 0;
}
