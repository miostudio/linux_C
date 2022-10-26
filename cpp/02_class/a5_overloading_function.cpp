#include<iostream>
#include<string>
#include<cstring>
using namespace std;

//定义一个类
class Book{
private:
    string name;
    float price;
public:
    // 两个构造函数的重载
    Book()=default;
    Book(string str, float val):name(str), price(val){}
    Book(float val, string str):name(str), price(val){}

    void show(){
        printf("class Book: name:%s, price:%0.2f\n", name.c_str(), price);
    }
};

int main(){
    Book book1("c lang", 20.5);
    Book book2(60.5, "c++ lang"), book3;
    book1.show();
    book2.show();
    book3.show();
}