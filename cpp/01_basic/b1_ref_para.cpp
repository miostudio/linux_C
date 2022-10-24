#include<iostream>
using namespace std;

//使用指针或引用作为参数，修改值
void mod1(int *p){
    printf("%p\n", p);
    *p=10;
}
void mod2(int &p){ //传递引用，就相当于把原始数据传入了：指针的功能 + 原始变量名的写法
    printf("%p\n", &p);
    p=20;
}
void mod0(int p){
    printf("%p\n", &p);
    p=-100;
}

int main(){
    int x=0;
    printf("origin x=%d | %p\n", x, &x);

    // 传入指针
    mod1(&x);
    printf("1 x=%d\n", x); //10

    // 传入引用
    mod2(x);
    printf("2 x=%d\n", x); //20

    // 传入值
    mod0(x);
    printf("0 x=%d\n", x); //20
}