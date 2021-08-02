#include<stdio.h>
void swap(int *a, int *b){
    if (*a != *b){
        *a ^= *b;
        *b ^= *a;
        *a ^= *b;
    }
}
int main(){
	int a=3, b=4;
	printf("a=%d, b=%d\n", a, b);
	swap(&a, &b);
	printf("a=%d, b=%d\n", a, b);
}
