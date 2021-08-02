#include<stdio.h>
int main(){
	//fprintf(fp, "xx %c $d", char1, 20);
	fprintf(stdout, "please input a %s:\n", "number");
	// 等同于 
	printf("please input a %s:\n", "number");
	
	int a;
	//scanf("%d", &a);
	// 等价于
	//fscanf(fp,"%s%s%s%s%s%s",&c1,&c2,&c3,&c4,&c5,&c6);
	fscanf(stdin, "%d", &a);
	printf("your input is %d\n", a);
	
	//错误流
	if(a<0){
		fprintf(stderr, "the value must be positive! But you input %d\n", a);
		return 1;
	}
	
	return 0;
}
