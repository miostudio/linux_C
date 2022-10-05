#include<stdio.h>

void demo1(){
    //printf("\033[nmyour text\033[0m\n");
    // font color
    printf("\033[31m red text\033[0m\n");
    printf("\033[32m green text\033[0m\n");
    printf("\033[33m yellow text\033[0m\n");
    printf("\033[34m blue text\033[0m\n");
    printf("\033[35m purple text\033[0m\n");
    printf("\033[36m dark green text\033[0m\n");
    printf("\033[37m white text\033[0m\n");
    // background
    printf("\033[41;37m red_bg, white_color text\033[0m\n");
    printf("\033[42;33m green_bg, yellow_color text\033[0m\n");
    // in one line
    printf("\033[45;33m%s\033[0m\033[47;30m%s\033[0m\n", "What day is it today?", "Today is Monday.");
}
/*
30:黑
红色	绿色	黄色	蓝色	紫色	深绿色	白色
31m	    32m	   33m	   34m	   35m	  36m	 37m
38 打开下划线,设置默认前景色 
39 关闭下划线,设置默认前景色 

# 字背景颜色范围:40--49
40 黑色背景 
41 红色背景 
42 绿色背景 
43 棕色背景 
44 蓝色背景 
45 品红背景 
46 孔雀蓝背景 
47 白色背景 
48 不知道什么东西
49 设置默认背景色

in C++: cout << "\033[33m" << str << "\033[0m" << endl;
*/


// demo II
void print_red(char arr[]){
    printf("\033[31m%s\033[0m", arr);
}

void print_yellow(char arr[]){
    printf("\033[33m%s\033[0m", arr);
}

void demo2(){
    print_red("who are you?");
    printf("\n");

    print_yellow("I am Tom.");
    printf("\n");
}

int main(){
    demo1();
    printf("\n");
    demo2();
    return 0;
}
