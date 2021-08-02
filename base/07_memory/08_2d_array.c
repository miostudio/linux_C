#include<stdio.h>
int main(){
	char str[][5]={"this", "is", "dog"};
	int i=0;
	for(;i<3;i++){
		printf("str[%d]=%s \t%p\n", i, str[i], &str[i]);
	}
	return 0;
}
