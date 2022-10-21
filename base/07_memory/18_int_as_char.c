#include<stdio.h>

// csapp P32 字节表示的示例
typedef unsigned char *byte_ptr;
// 使用 typedef 给数据命名，能极大的提高代码的可读性。因为深度嵌套的类型声明很难读懂。


void show_bytes(byte_ptr start, size_t len){
    size_t i;
    for(i=0; i<len; i++){
        printf(" %.2x", start[i]); //todo??
    }
    printf("\n");
}

//显示int的二进制：从地址低位到高位
void show_int(int x){
    show_bytes( (byte_ptr) &x, sizeof(int) );
}

//显示float的二进制：
void show_float(float x){
    show_bytes( (byte_ptr) &x, sizeof(float) );
}

void show_pointer(void *x){
    show_bytes( (byte_ptr) &x, sizeof(void *) );
}

//测试 
void test_show_bytes(int val){
    int ival = val;
    float fval=(float)val;
    int *pval=&ival;
    show_int(val); //39 30 00 00
    show_float(fval);
    show_pointer(pval);
}

int main(){
    int y=12345;
    printf("y=%d, 0x%X\n", y, y); //y=12345, 0x3039
    test_show_bytes(y);

    return 0;
}
/*
y=12345, 0x3039
 39 30 00 00
 00 e4 40 46
 98 a6 4a 7e ff 7f 00 00
数字的最低位 39 最先打印出来，说明该机器是小端法。
指针与众不同，是8位的。
*/