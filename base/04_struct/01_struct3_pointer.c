#include<stdio.h>
#include<string.h>

// 指向结构体的指针
struct Book{
    char name[20];
    float price;
};

int main(){
    // 1.定义指向结构体变量的指针
    struct Book book1={"C lang", 50.5}, *pb;
    // 2.赋值: 获取变量地址
    pb=&book1;

    // 3.引用结构体变量的3种方法
    printf("1 Book: name:%s, price:%0.2f\n", book1.name, book1.price);
    printf("2 Book: name:%s, price:%0.2f\n", (*pb).name, (*pb).price);
    printf("3 Book: name:%s, price:%0.2f\n", pb->name, pb->price);
    // 修改元素的值
    pb->price=100.8;
    printf("4 Book: name:%s, price:%4.2f\n", book1.name, book1.price);
}