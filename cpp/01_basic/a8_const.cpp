#include<iostream>
using namespace std;

#define WIDTH 25  //不是c++语句，编译前预处理掉了，不加分号结尾

const int HEIGHT = 4; //加分号结尾

int main(){
    int area = WIDTH * HEIGHT;
    cout << "area=" << area << endl;

    return 0;
}