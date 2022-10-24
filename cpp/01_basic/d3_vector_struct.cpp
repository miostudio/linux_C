#include<iostream>
#include<vector>
//#include <string.h>
#include <cstring>
//using namespace std;

// vector 保存结构体
struct Book{
    std::string name; //版本1 使用string
    double price;
};

void demo1(){
    Book book; //临时变量
    std::vector<Book> shelf; //书架，保存各种书

    //添加两本书
    book.name="C lang"; book.price=42.8;
    shelf.push_back(book);

    book.name="C++ lang"; book.price=82.6;
    shelf.push_back(book);

    //打印：下标法
    for(int i=0; i<shelf.size(); i++){
        printf("%p | shelf[%d].name=%s, .price=%0.2f\n", &shelf[i], i, shelf[i].name.c_str(), shelf[i].price);
    }
    printf("\n");

    //打印：迭代器法
    for(auto be=shelf.cbegin(); be<shelf.cend(); be++){
        printf("%p | name:%s, price:%0.2f\n", &*be, be->name.c_str(), be->price);
    }
    printf("\n");

    //把容器中的记录复制到结构体中
    printf("sizeof Book:%ld, shelf:%ld, shelf[0]:%ld\n", sizeof(Book), sizeof(shelf), sizeof(shelf[0]));
    printf("addr: &book=%p, &shelf[0]=%p\n", &book, &shelf[0]);
    for(int i=0; i<shelf.size(); i++){
        //memcpy(&book, &shelf[i], sizeof(Book)); //这句话注释掉，就不报错了
        printf("%d> book.name=%s, book.price=%0.2f\n", i, book.name.c_str(), book.price);
    }
}
/*
//为什么运行结束还给出一个 报错？
the end;
free(): invalid pointer
Aborted (core dumped)
*/



struct Book2{
    char name[28]; //版本2 使用C风格字符串
    double price;
};

void demo2(){
    Book2 book; //临时变量
    std::vector<Book2> shelf; //书架，保存各种书

    //添加两本书
    strcpy(book.name, "C lang"); book.price=42.8;
    shelf.push_back(book);

    strcpy(book.name, "C++ lang"); book.price=82.6;
    shelf.push_back(book);

    //打印：下标法
    for(int i=0; i<shelf.size(); i++){
        printf("%p | shelf[%d].name=%s, .price=%0.2f\n", &shelf[i], i, shelf[i].name, shelf[i].price);
    }
    printf("\n");

    //打印：迭代器法
    for(auto be=shelf.cbegin(); be<shelf.cend(); be++){
        printf("%p | name:%s, price:%0.2f\n", &*be, be->name, be->price);
    }
    printf("\n");

    //把容器中的记录复制到结构体中
    printf("sizeof Book:%ld, shelf:%ld, shelf[0]:%ld\n", sizeof(Book2), sizeof(shelf), sizeof(shelf[0]));
    printf("addr: &book=%p, &shelf[0]=%p\n", &book, &shelf[0]);
    for(int i=0; i<shelf.size(); i++){
        memcpy(&book, &shelf[i], sizeof(Book2)); // 不报错
        printf("%d> book.name=%s, book.price=%0.2f\n", i, book.name, book.price);
    }
}


int main(){
    //demo1();
    demo2();

    printf("the end;\n"); 
    return 0;
}