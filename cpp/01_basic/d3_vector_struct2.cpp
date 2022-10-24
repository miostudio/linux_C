#include<iostream>
#include<vector>
#include <cstring>

// vector 保存结构体
struct Book{
    std::string name; //版本1 使用string
    double price;
};

// 重复错误: 
void demo1(){
    Book book1, book2;
    std::vector<Book> shelf;
    
    //1.给book1赋值
    book1.name="C lang"; book1.price=40.8;
    //2.把book1添加到vector中
    shelf.push_back(book1);

    //3.把内容从 vector[0] 复制到 book2
    memcpy(&book2, &shelf[0], sizeof(Book)+1); //double free or corruption (out)
    //memcpy(&book2, &book1, sizeof(Book)); //munmap_chunk(): invalid pointer
    //book2=book1; //不报错
    book2=shelf[0]; //也不报错

    //打印结果
    std::cout << book2.name << ", " << book2.price << std::endl;
}

void demo2(){
    std::string s1="hello", s2;
    printf("sizeof:%ld, %ld\n", sizeof(s1), sizeof(s2));

    //有人说: string内部动态分配了内存，memcpy是按位拷贝，拷贝之后两个结构体里的string对象内部动态分配的内存都指向同一个地址，析构的时候同一块内存就free两次了
    //memcpy(&s2, &s1, sizeof(s1));

    //动态创建内存
    char *pHeap=(char *)malloc(sizeof(char)*10);
    strcpy(pHeap, "in heap now");
    printf("[heap] %s, %p\n", pHeap, pHeap);
    free(pHeap);

    //看地址
    int a=12;
    printf("addr: &a=%p\n", &a);
    printf("addr: &s1=%p, s1.c_str()=%p\n", &s1, s1.c_str() );

    const char *b=s1.c_str();
    printf(">>%s | %p\n", b, b);

    auto be=s1.begin();
    printf("addr: &*be=%p\n", &*be);
    for(auto i: s1){
        printf("\t %c | %p\n", i, &i);
    }

    //看大小
    printf("size: %ld, %ld\n", sizeof(s1), strlen(s1.c_str()) );

    std::cout << "s2=" << s2 << std::endl;
}


int main(){
    //demo1();
    demo2();


    return 0;
}