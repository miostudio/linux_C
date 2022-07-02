#include<iostream>
using namespace std;

int main(){
    int a=1;
    cout << "1a value of a:" << a << endl;

    { 
        //块语句有变量范围吗？
        a=200; //块内被修改过，然后能影响外面
        cout << "2a value of a:" << a << endl;

        int b=50; // 块内定义的，块外无法访问
        cout << "\t1b value of b:" << b << endl;
    }
    cout << "3a value of a:" << a << endl;
    //cout << "\t2b value of b:" << b << endl;
    
    return 0;
}