#include<stdio.h>
#include<stdarg.h>

/**
 * @brief 可变参数的函数示例
 * C语言采用va_start宏、va_end宏和一系列函数来实现可变参数功能。
 * 可变参数只能放到最后
 * 可变参数 ... 之前，至少有一个参数
 * 可变参数 ... 之前，最后一个参数表示可变参数个数
 **/
int my_sum(int arg_num, ...){
    int val=0;
    
    //1. 声明一个可变参数变量
    va_list args;

    // 2. 开始处理可变参数
    va_start(args, arg_num);
    for(int i=0; i<arg_num; i++){
        val += va_arg(args, int); //3. 从 args 中读取一个int类型
    }
    //4. 结束处理可变参数
    va_end(args);

    return val;
}

int main(){
    printf("sum = %d\n", my_sum(2,10,20));
    printf("sum = %d\n", my_sum(5, 1,2,3,4,5));

    return 0;
}