#include<iostream>
using namespace std;

//变量声明，可以多次声明，在多个文件种声明
extern int a,b;
extern float f;

int main(){
    //变量定义，只能在某一个文件被定义一次
    int a,b;
    float f;

    //实际初始化
    a=10;
    b=20;
    f=10.1/3.0;

    cout << a+b << endl;
    cout << f << endl;

    return 0;
}