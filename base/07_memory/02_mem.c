//求正方形、长方形面积
//为了检查各个变量在内存中的位置，加入很多无关变量。
#include<stdio.h>

int global =0;
int rect(int a, int b){
	static int count=0;
	count++;
	global++;
	int s=a*b;
	return s;
}

int square(int a){
	static int count =0;
	count++;
	global++;
	int s=rect(a, a);
	return s;
}

int main(){
	int a=3, b=4;
	int *pa=&a, *pb=&b;
	int *pglobal=&global;
	int (*psquare)(int a)=&square;
	int s=(*psquare)(a);
	printf("%d\n", s);
}

