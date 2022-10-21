#include<stdio.h>

int main(){
    int x=0x12345678;
    printf("x=0x%X\n", x);

    int y= x & 0xFF; //只要低字节
    printf("y=0x%X\n", y);

    //舍弃低字节
    printf("z=0x%X\n", x & (~0xFF));

    return 0;
}