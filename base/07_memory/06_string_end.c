#include<stdio.h>
int main(){
	char str[]="this is";
	char str3[10]="OK";
	printf("%s\n", str);
	//使用指针操作提前终止
	str[3]='\0';
	printf("%s\n", str);
	
	int i;
	for(i=0; i<8; i++){
		printf("%c\n", str[i]);
	}
	return 0;
}
