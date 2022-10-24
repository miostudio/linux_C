#include<iostream>
using namespace std;

//1.不能返回局部变量的引用(和指针一样)，局部变量在函数返回后会释放
int &fn1(int x){
    int y=x+10;
    return y;
}
void demo1(){
    int &a1=fn1(10); //warning: reference to local variable ‘y’ returned
    printf("a1=%d\n", a1); //Run: Segmentation fault (core dumped)
}

//2.不能返回函数内部动态分配的内存的引用，会导致无法释放


//3. 经常用于返回成员变量的引用，采用 const 约束可以防止在类外部修改成员变量的值

int &fn(int &x, int &y){
    printf("x=%d(%p), y=%d(%p)\n", x,&x, y, &y);
    return (x>y? x : y);
}
void demo2(){
    int a=10, b=200;
    printf("a=%d(%p), b=%d(%p)\n", a,&a, b, &b);

    int res=fn(a, b);
    printf("res=%d(%p)\n", res, &res); //返回的是引用，但是接收的时候拷贝了，所以地址变了

    int &ref=fn(a, b);
    printf("ref=%d(%p)\n", ref, &ref); //返回的是引用，接收的也是引用，所以地址没变
    //修改ref的值，也即是修改原始值(较大的那个)
    ref=-5000;
    printf("==> a=%d(%p), b=%d(%p)\n", a,&a, b, &b);
}

int main(){
    //demo1(); //编译时第一个的warning可以忽略
    demo2();
}