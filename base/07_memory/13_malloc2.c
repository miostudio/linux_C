//内存越界
#include<stdio.h>
#include<stdlib.h>
int main(){
	int i;
	int len = 4;
	int *pt = (int*)malloc(len*sizeof(int)); //返回的是空指针，可以主动转换为某个类型
	int *p = pt;

	for(i=0;i<len;i++){
		*p=i;
		p++;
	}

	*p = 5;
	return 0;
}
