#include<iostream>
using namespace std;

// 全局静态变量
static int count = 10;

void func1(void){
    static int i=2; //局部静态变量
    i++;
    cout << "i=" <<i << 
        ", count=" << count << endl; //内部可以使用全局变量
}

int main(){
    while(count--){
        func1();
    }
    //cout << "i=" << i << endl; //报错 i 未声明。局部变量只能用在局部: 函数内或块内
    return 0;
}