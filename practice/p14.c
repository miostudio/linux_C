#include<stdio.h>
int main(){
	char c;
	int letter=0, blank=0, digits=0, other=0;
	while( (c=getchar())!='\n' ){
		if( (c>='a' && c<='z') || (c>='A' && c<='Z') ){
			letter++;
		}else if( c>='0' && c<='9' ){
			digits++;
		}else if( ' '==c ){
			blank++;
		}else
			other++;
	}
	
	printf("字符统计: \n 字母: %d\n 数字: %d\n 空格: %d\n 其他:%d\n", letter, digits, blank, other);
}
