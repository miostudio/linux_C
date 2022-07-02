#include<iostream>
using namespace std;

int main(){
    enum Color {red, green, blue} c;
    c=blue;
    cout << "c=" << c << endl; //2

    //再定义一个变量
    Color c2=red;
    cout << "c2=" << c2 << endl; //0

    //定义值的枚举，前面的值不变，后面默认比前面递增1
    enum Week {Mon, Tue, Wed=13, Thu, Fri, Sat, Sun};
    Week w1=Mon, w2=Fri;
    cout << "\nw1=" << w1 << endl; //0
    cout << "w2=" << w2 << endl; //15

    cout << "size of enum:" << sizeof(w2) << endl; //4

    return 0;
}
