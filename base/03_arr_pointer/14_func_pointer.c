#include<stdio.h>

void max(){
	printf("This is function max()\n");
}

int main(){
	printf("function %p(p=%p)\n", max, &max);
}
