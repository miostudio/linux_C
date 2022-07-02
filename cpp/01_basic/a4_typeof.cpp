//怎么查询数据类型占了多少字符？

#include<iostream>
using namespace std;

int main(){
    //先定义变量，然后查询该该变量
    char a0;
    int a1;

    cout << "sizeof char:" << sizeof(a0) << endl; //1 byte = 8bit = 符号位+2^7， [-128, 127] or [0, 255]
    //c++ 不会自动初始化，所以获取的内存空间有什么，它就直接读取了
    cout << "sizeof int:" << sizeof(a1) << " value=" << a1 << endl; //4  
    
    //也可以直接用数据类型定义符
    cout << "sizeof short:" << sizeof(short) << endl; //2
    cout << "sizeof long:" << sizeof(long) << endl; //8
    
    cout << "sizeof float:" << sizeof(float) << endl; //4
    cout << "sizeof double:" << sizeof(double) << endl; //8
    return 0;
}

