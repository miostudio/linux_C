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

// 打印int的二进制，是4个字节
void show_int(int *ptr, int enter){
    //假设是小端，先打印最后一个字节
    for(int i=3; i>=0; i--){
        /* 方法1 可以
        unsigned char *p=(unsigned char*) ptr + i;
        show_byte((unsigned char *)p, 0);
        */
        //方法2 也可以: 优先级是 强制转换 > 加号
        show_byte( (unsigned char *)ptr+i, 0);
    }
    if(enter) printf("\n");
}

//打印float的二进制，是4个字节
void show_float(float *ptr, int enter){
    //假设是小端，先打印最后一个字节
    for(int i=3; i>=0; i--){
        show_byte( (unsigned char *)ptr + i, 0);
    }
    if(enter) printf("\n");
}

int main(){
    // a char
    char s='A';
    show_byte( &s, 0);
    printf(" %c %d\n", s, s);
    
    // an int
    int a=-2;  //0x41;
    show_byte( (char *)&a, 0);
    printf(" %d\n", a);
    show_int(&a, 0);
    printf(" %d\n", a);

    // an float
    // https://blog.csdn.net/wangjunliang/article/details/127191707
    float f1=1.74, f2=0.87;
    show_float(&f1, 0); printf(" %f\n", f1);
    show_float(&f2, 0); printf(" %f\n", f2);

    return 0;
}