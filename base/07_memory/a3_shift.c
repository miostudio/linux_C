#include<stdio.h>

//打印1byte = 8bits的二进制表示
void show_byte(const unsigned char * ptr, int enter) {
    unsigned char j=*ptr;
    for(int i=7; i>=0; i--){
        printf("%s", (*ptr & (1<<i))==0? "0":"1" );
    }
    printf(" ");
    if(enter) printf("\n");
}

void demo(int x){
    printf("x=%d, 0x%x\n", x, x);
    show_byte((unsigned char *) &x, 1);

    //左移4位
    char x2=x<<4;
    show_byte((unsigned char *) &x2, 1);

    //右移4位: 经测试，是算术右移，保持符号不变
    char x3=x>>4;
    show_byte((unsigned char *) &x3, 1);
}


int main(){
    char x=99;
    char y=149;
    demo(x);
    printf("\n");
    demo(y);

    return 0;
}