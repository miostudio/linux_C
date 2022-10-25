basics of C++: non class part.


a1.cpp hello world
a2.cpp string
    $ g++ a2.cpp
    $ ./a.out
    hello, vscode
    hello, world

a3.cpp 块语句有变量范围吗？ 有，只是按照声明位置确定。声明在函数内部或者块中的是局部变量。
a4_typeof.cpp 怎么查询数据类型占了多少字符？
a5_typedef.cpp 给已有类型取别名
a6_enum.cpp 枚举类型 enum enum-name { list of names } var-list; 
a7_declaration_params.cpp 可以在 C++ 程序中多次声明一个变量，但变量只能在某个文件、函数或代码块中被定义一次。//todo 声明 定义 啥区别？ 看例子:
a7_declaration_function.cpp
a8_const.cpp 常量的定义，#define SOMETHING value  或 const float PI=3.1415
a9_static.cpp  static 存储类


引用
b1_ref_para.cpp 引用作为参数可以修改值，和指针功能类似
b2_ref_return.cpp 返回引用


string 类
c1.cpp #C风格的字符串和string字符串，及转换

vector 容器
d1.cpp 使用容器保存int,增删改查
d2.cpp vector 保存string。问题：为什么获取的地址不同呢？
d3.cpp vector 保存结构体。问题：为什么该程序最后报错：free(): invalid pointer？
    问题可能是 string 不能使用 memcpy 按位复制
d4.cpp vector 元素的增删: push_back/insert, erase/pop_back/clear, empty/size
d5.cpp 容器的排序。作业: 封装一个随机数函数  http://www.freecplus.net/2cf62b4695a8462dbbab205af42df54f.html


