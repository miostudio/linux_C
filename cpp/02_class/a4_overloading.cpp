#include<iostream>
#include<string.h>
using namespace std;

// 重载运算符，格式 operator运算符
//示例：判断两个类是否相等
class Book{
public:
    char name[20];
    double price;

    bool operator==(const Book &book); //重载运算符，可以看做是类的一个函数
};

int main(){
    Book book1, book2, book3;
    strcpy(book1.name, "C lang");
    strcpy(book2.name, "C++ lang");
    strcpy(book3.name, "C lang");

    printf("b1 and b2: %s\n", book1==book2?"same":"diff"); //相当于调用了 book1 的 == 方法，把book2作为参宿传递给该函数，从而在函数内实现了比较。
    printf("b1 and b3: %s\n", book1==book3?"same":"diff");

    // 因为没有重载 != 所以调用直接编译报错: error: no match for ‘operator!=’ (operand types are ‘Book’ and ‘Book’)
    //printf("b1 and b3: %s\n", book1!=book3?"same":"diff");
}

//只要书名相同，就认为相同
bool Book::operator==(const Book &book){
    if( strcmp(name, book.name)==0 )
        return true;
    return false;
}
