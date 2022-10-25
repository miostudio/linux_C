#include<iostream>
#include<vector>
#include<algorithm>
#include <cstring>
using namespace std;

// vector 的排序
struct Book{
    char name[50];
    float price;
};

//自定义排序函数，按name 排序
bool sortByName(const Book &b1, const Book &b2){
    return (strcmp(b1.name, b2.name) ) ? true : false;
}

//自定义排序，按 price 排序
bool sortByPrice(const Book &b1, const Book &b2){
    return b1.price > b2.price ? true:false;
}

int main(){
    Book b1; //单个书
    std::vector<Book> shelf; //保存很多书

    strcpy(b1.name, "Python"); b1.price=20.1; shelf.push_back(b1);
    strcpy(b1.name, "Java"); b1.price=70.5; shelf.push_back(b1);
    strcpy(b1.name, "C++"); b1.price=45.2; shelf.push_back(b1);
    strcpy(b1.name, "iOS"); b1.price=35.2; shelf.push_back(b1);

    //排序
    //sort(shelf.begin(), shelf.end()); //不传入比较函数会报错
    sort(shelf.begin(), shelf.end(), sortByName); //按名字排序
    //sort(shelf.begin(), shelf.end(), sortByPrice); //按价格排序

    for(auto i: shelf)
        //printf("%s, %0.2f\n", );
        std::cout<< i.name << ", " << i.price << std::endl;
    printf("\n");
}
