# Learn C under Ubuntu linux


## link to:
- [C note - base](https://github.com/DawnEve/txtBlog/blob/master/data/c/c101-base.txt)
- [C note - adv](https://github.com/DawnEve/txtBlog/blob/master/data/c/c102-adv.txt)
- [dawneve/learn_C](https://github.com/dawneve/learn_C): learn C on win7 at home


## Dir structure

- 建立自己的库，保存好用的工具函数和类: `Miolib/_public.h` 和 `Miolib/_public.cpp`
- 注意：
  * 该repo练习为主，会持续增删改，所以该库仅用于汇集我写过的好代码片段(函数和类)，不建议用于编译。
  * 随着理解的深入，可能会有重复函数名，最好注明来源的文件夹，并把不好的版本删除或者注释掉。
  * 做好注释：目的、参数意义、返回值、使用示例。



```
$ pwd #Y station
/data/wangjl/project/linux_C


$ tree -L 1
.
├── base: 见下文
├── makefile: 多文件编译
├── adv: socket, multi thread, 
├── csapp 一本书
├── practice
├── algorithm
├── backup //不需要Git跟踪的代码，暂存
├── Miolib  //我自己的工具库: 函数 + 类
├── changeLog.txt ==> Git 历史记录
└── ReadMe.md: 本简介


more detailed:
├── base
│   ├── 01_base 基本数据结构、控制结构(if/switch/for/while/break/continue)、带颜色打印、
│   ├── 02_function: 函数、main函数的参数、多文件包含
│   ├── 03_arr_pointer: 数组与指针、字符串、数组作为参数、返回数组、函数指针
│   ├── 04_struct: 结构体的定义与初始化、结构体指针、结构体数组、结构体作为参数
│   ├── 05_files: 文件读写
│   ├── 06_linux: 使用管道符串联程序
│   ├── 07_memory: 内存管理、内存表示
│   ├── 08_sort: 数组排序
│   └── 09_bit: 位运算
└── practice


|-- adv/
  |- 01_socket
  |- 02_multi_thread


|-- algorithm/
  |- 01_array
  |- 02_linkedList
  |- 03_stack

  |- 05_tree

|-- cpp/ 更多c++ 见 github.com/DawnEve/learnCpp
  |- 01_basic/
  |- 02_class/
```
