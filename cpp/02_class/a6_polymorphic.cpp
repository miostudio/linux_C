#include<iostream>
using namespace std;

class Book{
public:
    string name;
    float price;
    void show(){
        cout << "Book.show(): " << name << ", price:"<< price << endl;
    };
};

class SmallBook: public Book{ //继承自 Book
public:
    void show(){
        cout << "SmallBook.show(): " << name << ", price:"<< price << endl;
    };
};

//静态指针：在编译期间就已经设置好调用方法(指针所属类的方法)了
void demo1(){
    SmallBook sb1, sb2;
    sb1.name="c lang sim"; sb1.price=10.5;
    sb1.show();
    cout << endl;

    //声明指针
    Book *pB; //指向父类的指针
    SmallBook *pSB; //指向子类的指针

    pB=pSB=&sb1; //为指针赋值

    pB->show(); //调用父类的方法
    pSB->show(); //调用子类的方法
}

int main(){
    demo1();
}
