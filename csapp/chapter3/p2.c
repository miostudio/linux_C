#include<stdio.h>

extern int Max(int, int);
int main(){
	int a1=1, a2=2;
	int x=Max(a1, a2);
	printf("Max(%d, %d)=%d\n", a1, a2, x);
}

/*
$ gcc -std=c11 -Og -o a.out p1.c p2.c
$ ./a.out
Max(1, 2)=2
*/