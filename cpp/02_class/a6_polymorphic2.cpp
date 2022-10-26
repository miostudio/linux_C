#include<iostream>
using namespace std;

class Book{
public:
    string name;
    float price;
    Book()=default;
    Book(string s, float val): name(s), price(val){};// 构造函数
    //Book(string &s, float &val): name(s), price(val){};// 构造函数

    //添加关键字 virtual 的函数叫虚函数。
    //在程序中可以根据所调用的对象类型来选择调用的函数，这种操作被称为动态链接，或后期绑定。
    virtual void show(){ 
        cout << "Book.show(): " << name << ", price:"<< price << endl;
    };
    // vitual 开头，没有函数定义，在子类中实现的函数定义，叫做 纯虚函数
    virtual void show2()=0; // 声明一个纯虚函数。
};

class SmallBook: public Book{ //继承自 Book
public:
    /* 
    SmallBook()=default;
    SmallBook(string s, float val): Book(s, val){} //子类的构造函数如何继承？这样一条一条写
    */
   using Book::Book; //这一句继承父类的构造函数

    void show(){
        cout << "SmallBook.show(): " << name << ", price:"<< price << endl;
    };
    void show2(){
        cout << "SmallBook.show2();" << endl;
    }
};

class BigBook: public Book{ //继承自 Book
public:
    using Book::Book;
    void show(){
        cout << "BigBook.show(): " << name << ", price:"<< price << endl;
    };
    void show2(){
        cout << "BigBook.show2();" << endl;
    }
};

//动态指针：运行期间，根据父类的引用（指针）指向的对象来确定具体调用哪一个类的虚函数
void demo2(){
    SmallBook sb1;
    sb1.name="c lang sim"; sb1.price=10.5; 
    sb1.show();

    BigBook bb1;
    bb1.name="c lang Big"; bb1.price=80.8; 
    bb1.show();
    cout << endl;

    //声明指针
    Book *pB; //指向父类的指针
    SmallBook *pSB; //指向子类的指针

    pB=pSB=&sb1; //为指针赋值
    pSB->show(); //调用子类1的方法

    //编译器看的是指针的内容，而不是指针的类型，这句是多态的一般使用方法
    pB->show(); //调用【子类1】的方法
    pB=&bb1; 
    pB->show(); //调用【子类2】的方法

    //纯虚函数所在的(抽象)类不能实例化
    //Book b1; //error: cannot declare variable ‘b1’ to be of abstract type ‘Book’
    //b1.name="c lang"; b1.price=20.6; b1.show();
}

void read(Book *b){
    cout << "*pointer ";
    b->show();
}
void read(Book &b){
    cout << "&ref ";
    b.show();
}

void demo3(){
    SmallBook sb1(string("Python small"), 5.6);
    read(sb1); //调用引用版

    //调用指针版
    //read(new SmallBook("Python small", 5.6));  //这样写无法释放内存
    SmallBook *p1=new SmallBook("Python small", 5.6);
    BigBook *p2=new BigBook("Python STL", 105.8);
    read(p1);free(p1);
    read(p2);free(p2);    
}

int main(){
    //demo2();
    demo3();
}
