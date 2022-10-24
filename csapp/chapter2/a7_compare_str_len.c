#include<stdio.h>
#include<string.h>

//buggy code P58
int strlonger(char *s, char *t){
    return strlen(s) - strlen(t) >0; //1.为什么这一行不行？
    //return strlen(s) > strlen(t);
}

// 函数原型 size_t strlen(const char *s);
// 其中 size_t 是定义成 unsigned int 的。

int main(){
    char *x="123", *y="this is a book";
    printf("result of function: %d\n", strlonger(x, y));


    // 原因: 2个 unsigned 直接相减，结果还是 unsigned, 和0比较，就是一个正数
    unsigned int a=1, b=20;
    printf("(a-b):%d\n", a-b);
    printf("(a-b) >0 :%d (why?)\n", (a-b) >0); //结果是错误的
    printf("(int)(a-b) >0: %d\n", (int)(a-b) >0);

    printf("sizeof size_t:%ld, int:%ld\n", sizeof(size_t), sizeof(int)); //8个字节 size_t 是一个 unsigned long
    size_t a1=0, a2=a1-1;
    printf("a2=%lu\n", a2);

    return 0;
}
