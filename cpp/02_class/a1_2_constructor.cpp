#include<iostream>
using namespace std;

//构造函数和析构函数;

class Box{
    public:
        Box(){
            cout <<"调用构造函数 constructor" << endl;
        }
        ~Box(){
            cout << "调用析构函数 destructor ~~~~~" <<endl;
        }
};

int main(){
    Box* box=new Box; // 没加*报错： new 返回的是指针
    delete box;

    printf("\n");
    Box* boxes=new Box[2];
    delete [] boxes;
    
    return 0;
}