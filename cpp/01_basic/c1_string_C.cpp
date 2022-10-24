#include<iostream>
#include<string.h>
#include<string>

//1. 示例：两种字符串的定义方式
void demo1(){
    // C风格的字符串
    char str1[10]="hi";
    printf("1. str1=%s\n", str1);
    //修改
    strcpy(str1, "world");
    printf("2. str1=%s\n", str1);

    // string 字符串
    std::string str2="hello";
    printf("3. str2=%s\n", str2.c_str());

    //1.拷贝 C to Cpp
    str2=str1;
    std::cout << "4. " << str2 << std::endl;

    //2.修改后拷贝 Cpp to C
    str2="C++ lang";
    std::cout << "5. " << str2 << std::endl;
    strcpy(str1, str2.c_str());
    printf("6. str1=%s\n", str1);
}

/*
string的重载的操作符
可以用=直接赋值。
可以用 ==、>、<、>=、<=、和!=比较字符串。
可以用+或者+=操作符连接两个字符串。
可以用[]获取指定位置的字符，类似数组。
*/
void demo2(){
    //成员函数
    std::string str3="hi,好";
    printf("size: %ld\n", str3.size() );
    printf("length: %ld\n", str3.length() ); //和 size 有啥区别?

    printf("str3[2]=%c\n", str3[2]); //通过下标获取字符

    std::cout << "str3=" << str3 << std::endl;
    str3.clear();
    std::cout << "str3=" << str3 << std::endl;
}

// string 就是一个类，通过动态分配内存，实现对字符串的存储，当内容不够时，会重新分配空间
void demo3(){
    std::string str4="a";
    printf("1 %p | %p | %p, size=%ld\n", &str4, str4.c_str(), &str4[0], str4.size() );
    // 字符串变量的地址&str4, 不是内部字符的地址

    str4="b"; //大小不变时，不开辟空间
    printf("2 %p | %p | %p, size=%ld\n", &str4, str4.c_str(), &str4[0], str4.size() );

    printf("capacity: %ld\n", str4.capacity()); //默认开辟了15个字符，超过就不够用了
    str4="C lang and C++ lang"; //大小不够，则重新开辟空间
    printf("3 %p | %p | %p, size=%ld\n", &str4, str4.c_str(), &str4[0], str4.size() );
}

int main(){
    demo1();
    printf("\n"); demo2();
    printf("\n"); demo3();

    return 0;
}
