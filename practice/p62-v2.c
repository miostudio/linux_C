#include<stdio.h>
#include<stdlib.h>

//字符串长度
int strlen2(char *p){
	int n=0;
	while(*p!='\0'){
		n++;
		p++;
	}
	return n;
}

//复制字符段，并返回新指针
char *strcat2(char *p1, char *p2){
	//获取长度
	int n1=strlen2(p1), n2=strlen2(p2), i;

	//复制字符数组
	char *p3=malloc(sizeof(char)*(n1+n2+1));
	for(int i=0; i<n1; i++){
		*(p3++)=*(p1++);		
	}
	for(int i=0; i<n2; i++){
		*(p3++)=*(p2++);
	}
	//*p3='\0';
	return p3-n1-n2;
}

int main(){
	char *c1="hello";
	char *c2=" world!";
	
	char *pstr=strcat2(c1, c2);
	printf("%s|\n", pstr);
	free(pstr);
	return 0;
}
