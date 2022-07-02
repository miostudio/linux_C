#include<iostream>
using namespace std;

//函数声明
int add(int x, int y); //如果不提前声明，就要在使用前定义。

int main(){
    cout<< add(10, 8) << endl;

    return 0;
}

//函数定义
int add(int a, int b){
    return a+b;
}