#include<stdio.h>
#include <limits.h>
/*
#define INT_MAX 2147483647
#define INT_MMIN (-INT_MAX - 1)
*/

int main(){
    int x1=INT_MAX, x2=INT_MIN;
    printf("int max: %d, min: %d\n", x1, x2);
    
    x1+=1; x2-=1;
    printf("int max: %d, min: %d\n", x1, x2);

    printf("%d\n", 1<<31);
}