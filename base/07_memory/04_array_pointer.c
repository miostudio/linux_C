#include<stdio.h>
int main(){
	int arr[]={1,20,303, 444};
	int *p=arr;
	//使用指针改变值
	p[3]=505;
	for(int i=0; i<4; i++){
		//使用指针下标，输出数组
		printf("p[%d]=%d\n", i, p[i]);
	}
	for(int i=0; i<4; i++){
		//使用指针偏移，输出数组
		printf("*(p+%d)=%d\n", i, *p);
		p++;
	}
	return 0;
}
