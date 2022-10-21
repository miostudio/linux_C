#include<stdio.h>

//只有一个基本类型内的char才有大小端问题: int, float, long
// char 内部('A')没有，char之间("ABCD")也没有大小端问题，都是按照从左到右，地址逐步增大的顺序

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

// 更一般的，支持打印任意个指定的字节
void show_bytes(void *p, int byteNum, int enter){
    unsigned char *ptr = (unsigned char *)p;
    //假设是小端，先打印最后一个字节
    for(int i=byteNum-1; i>=0; i--){
        show_byte( ptr + i, 0);
    }
    if(enter) printf("\n");
}

void demo1(char s){
    // a char
    //char s='A';
    show_byte( &s, 0);
    printf(" char %c %d\n", s, s);
}
void demo2(){
    // an int
    int a=-2;  //0x41;
    show_byte( (char *)&a, 0);  printf(" char %d\n", a);
    show_int(&a, 0); printf(" int(%ld) %d\n", sizeof(a), a);
}
void demo3(){
    // an float
    // https://blog.csdn.net/wangjunliang/article/details/127191707
    float f1=1.74, f2=0.87;
    show_float(&f1, 0); printf(" float(%ld) %f\n", sizeof(f1), f1);
    show_float(&f2, 0); printf(" float(%ld) %f\n", sizeof(f2), f2);
}

// 更一般的打印形式
void demo4(){
    long a1=2, a2=-2;
    show_bytes(&a1, sizeof(long), 0); printf(" long(%ld) %ld\n", sizeof(a1), a1);
    show_bytes(&a2, sizeof(long), 0); printf(" long(%ld) %ld\n", sizeof(a2), a2);
}

//获取字符串长度
int nchar(char *p){
    int i=0;
    while(*p++ != 0) //++优先，然后取值 *p
        i++;
    return i;
}
// 打印字符串
void demo5(char *x){
    show_bytes(x, nchar(x), 0);  printf(" string %s len=%d\n", x, nchar(x));
}

int main(){
    demo1('A');
    demo2();
    demo3();
    demo4(); // long 更一般的打印形式

    demo1('B');
    demo1('C');
    demo1('D');
    demo1('E');

    char *x="ABCDE";
    demo5(x); //只在一个char or 一个 long 内部有大小端问题，字符串就因该正常顺序输出: A在低地址p，后面的字母地址依次递增1
    for(int i=0; i<nchar(x); i++)
        printf("addr of %c:%p\n", x[i], &x[i]);
    return 0;
}