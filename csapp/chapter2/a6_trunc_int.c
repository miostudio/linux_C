#include<stdio.h>
#include "a0_lib.c"

int main(){
    int x=53191;
    short sx=(short) x;
    int y=sx;

    // length
    printf("sizeof int:%ld, short:%ld\n", sizeof(x), sizeof(sx));
    // value
    printf("int %d, short: %d\n", x, sx);

    // 查看二进制表示: 发现short是丢弃了int的高位2个字节
    show_bytes(&x, sizeof(x), 0); printf(" int(%ld) %d\n", sizeof(int), x);
    show_bytes(&sx, sizeof(sx), 0); printf(" short(%ld) %d\n", sizeof(short), sx);

    return 0;
}