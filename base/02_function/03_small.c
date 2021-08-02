#include<stdio.h>
void printNew(); //

static void say(){

	printNew();

	printf("hello, say() from another .c file\n");
	printNew();
}
