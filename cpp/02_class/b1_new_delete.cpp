#include<iostream>
#include<cstring>
using namespace std;

//new和delete的使用
// 实例1，int
void demo1(){
    int *pi = new int;
    *pi = 10;
    printf("pi=%p, *pi=%d\n", pi, *pi);

    delete pi;
}

// 实例2, 类
struct Book{
    char name[20];
    float price;
    //构造函数
    Book(){ std::cout << "Book()" << std::endl; }
    //析构函数
    ~Book(){ std::cout << "~Book()" << std::endl; }
    void show(){
        std::cout << "class Book: name:" << name 
            << ", price:"<< price << std::endl;
    }
};
void demo2(){
    Book *pB1=new Book; //new出来的是类，相当于创建对象，要调用构造函数。
    
    strcpy(pB1->name, "c++ lang");
    pB1->price=50.5;
    pB1->show();

    delete pB1; //delete 的时候调用析构函数
}

int main(){
    demo1();
    demo2();
}