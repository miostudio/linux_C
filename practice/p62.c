#include<stdio.h>
#include<stdlib.h>
char *strcat2(char *p1, char *p2){
	//获取长度
	int n1=0, n2=0, i;
	char *p0;
	
	p0=p1;
	while(*p0!='\0'){
		n1++;
		p0++;
	}
	p0=p2;
	while(*p0!='\0'){
		n2++;
		p0++;
	}
	
	//复制字符数组
	char *p3=malloc(sizeof(char)*(n1+n2+1));
	char *p3_0;
	p3_0=p3;
	for(int i=0; i<n1; i++){
		*(p3++)=*(p1++);		
	}
	for(int i=0; i<n2; i++){
		*(p3++)=*(p2++);		
	}
	*p3='\0';
	//p3=p3-n1-n2;
	return p3_0;
}

int main(){
	char *c1="hello";
	char *c2=" world!";
	
	char *pstr=strcat2(c1, c2);
	printf("%s\n", pstr);
	free(pstr);
	return 0;
}
